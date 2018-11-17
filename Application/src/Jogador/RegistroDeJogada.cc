#include "RegistroDeJogada.h"

RegistroDeJogada::RegistroDeJogada (const char* nome){
	_nome_jogada = nome;
	strcpy(_path,"save/");
	strcat(_path,_nome_jogada);
	strcat(_path,".txt");
}

RegistroDeJogada::~RegistroDeJogada (){

}

void RegistroDeJogada::salvarJogada(Jogador* j1, Jogador* j2, Lista<Inimigo*>* li, Lista<Plataforma*>* lp, int* pontuacao, const char* fase) {
	li->goToBottom();
	lp->goToBottom();

	ofstream save;
	save.open(_path);

	save << "F "  << fase << endl;

	save << "J "  << *pontuacao << endl;
	save << "K " << j1->GetPosicao().x << ' ' << j1->GetPosicao().y << endl;
	save << "L " << j2->GetPosicao().x << ' ' << j1->GetPosicao().y << endl;

	do {
		save << "I " << li->getWhatIsHere()->GetPosicao().x << ' '
			<< li->getWhatIsHere()->GetPosicao().y << ' ';
		save << li->getWhatIsHere()->QualTipo() << endl;

	} while(!li--);

	do{
		save << "P " << lp->getWhatIsHere()->GetPosicao().x << ' '
			<< lp->getWhatIsHere()->GetPosicao().y << ' '
			 << endl;
	}
	while(!lp--);
	save.close();
}

void RegistroDeJogada::carregarJogada (Jogador* j1, Jogador* j2, Lista<Inimigo*>* li, Lista<Plataforma*>* lp, int* pontuacao) {
	char* data = (char*) malloc(sizeof(char) * 64);

	li->mataLista();
	lp->mataLista();

	int xis, ipsilon, w, h, f;

	ifstream save;
	save.open(_path);

	while (!save.eof()) {
		save.getline(data,32);

		switch (data[0]) {
		case 'F':
			break;

		case 'J':
			sscanf(data,"J %d", pontuacao);
			break;

		case 'K':
			sscanf(data,"K %d %d", &xis, &ipsilon);
			j1->SetPosicao(xis, ipsilon);
			break;

		case 'L':
			sscanf(data,"L %d %d", &xis, &ipsilon);
			j2->SetPosicao(xis, ipsilon);
			break;

		case 'I':
			sscanf(data,"I %d %d %d", &xis, &ipsilon, &f);
			switch(f){
			case 0:
				li->colaNoFinal(new Mumia(j1, j2, xis, ipsilon));
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;

		case 'P':
			sscanf(data,"P %d %d %d %d", &xis, &ipsilon, &w, &h);
			lp->colaNoFinal(new Plataforma(xis, ipsilon, w, h));
			break;
		}
	}

	free(data);
	save.close();
}
