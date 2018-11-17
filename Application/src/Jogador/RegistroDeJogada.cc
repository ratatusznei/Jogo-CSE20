#include "RegistroDeJogada.h"

RegistroDeJogada::RegistroDeJogada(const char* nome){

    _nome_jogada = nome;
    strcpy(_path,"save/");
    strcat(_path,_nome_jogada);
    strcat(_path,".txt");

}

RegistroDeJogada::~RegistroDeJogada(){}

void RegistroDeJogada::salvarJogada(
Jogador* j1, Jogador* j2,
Lista<Inimigo*>* li, Lista<Plataforma*>* lp,
int* pontuacao, const char* fase){

    li->goToBottom();
    lp->goToBottom();

    ofstream save;
    save.open(_path);

    save << "F"  << endl << fase << endl << endl;

    save << "J"  << endl << *pontuacao << endl;
    save << "J1" << j1->GetPosicao().x << ' ' << j1->GetPosicao().y << endl;
    save << "J2" << j2->GetPosicao().x << ' ' << j1->GetPosicao().y << endl;

    save << endl << "I" << endl;

    do{

        save << li->getWhatIsHere()->GetPosicao().x << ' '
                << li->getWhatIsHere()->GetPosicao().y << ' ';
        save << li->getWhatIsHere()->QualTipo() << endl;

    }
    while(!li--);

    save << endl << "P" << endl;

    do{

        save << lp->getWhatIsHere()->GetPosicao().x << ' '
                << lp->getWhatIsHere()->GetPosicao().y << endl;

    }
    while(!lp--);

    free(_path);
    save.close();

}

void RegistroDeJogada::carregarJogada(
Jogador* j1, Jogador* j2,
Lista<Inimigo*>* li, Lista<Plataforma*>* lp,
int* pontuacao){



}
