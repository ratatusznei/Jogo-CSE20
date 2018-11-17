#include "Jogo.h"
#include<time.h>

Jogo::Jogo () {

    srand(clock());
}

Jogo::~Jogo () {
	//dtor
}

void Jogo::Executar () {

    CarregarFase("../res/fases/egypt.txt");

    GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();
	janela->CriaJanela(sf::VideoMode(Janela::largura, Janela::altura), Janela::titulo);

	sf::Event ev;

	GerenciadorDeInput i_j1;
	i_j1.SetKeyEsquerda(sf::Keyboard::A);
	i_j1.SetKeyDireita(sf::Keyboard::D);
	i_j1.SetKeyPulo(sf::Keyboard::W);
	i_j1.SetKeyAtaque(sf::Keyboard::Space);

	GerenciadorDeInput i_j2;
	i_j2.SetKeyEsquerda(sf::Keyboard::Left);
	i_j2.SetKeyDireita(sf::Keyboard::Right);
	i_j2.SetKeyPulo(sf::Keyboard::Up);
	i_j2.SetKeyAtaque(sf::Keyboard::RShift);

	Jogador j1(&i_j1, 20, 50);
	Jogador j2(&i_j2, 680, 0);

	j1.IniciarRobo();
	j2.IniciarDoctor();

	colisoes.Incluir(&j1);
	colisoes.Incluir(&j2);

	_listaPlataformas.goToTop();
	do{
        colisoes.Incluir(_listaPlataformas.getWhatIsHere());
	}
	while(!(++_listaPlataformas));

	_listaInimigos.goToTop();
	do{
        colisoes.Incluir(_listaInimigos.getWhatIsHere());
	}
	while(!(++_listaInimigos));

	sf::Texture t_fundo;
	t_fundo.loadFromFile("res/sprites/egypt_backg.png");

	sf::Sprite fundo(t_fundo);
	fundo.setScale(2, 2);

	while (1) {
		_fase->Executar(_jogador1,_jogador2,&_listaInimigos,&_listaPlataformas,&colisoes);
		janela->Desenhar(fundo);


		_listaPlataformas.goToTop();
        do{
            _listaPlataformas.getWhatIsHere()->Desenhar();
        }
        while(!(++_listaPlataformas));


        _listaInimigos.goToTop();
        do{
            _listaInimigos.getWhatIsHere()->Desenhar();
        }
        while(!(++_listaInimigos));


        j1.Desenhar();
        j2.Desenhar();

        janela->Atualizar();

	}


}

void Jogo::CarregarFase (char *path) {

    _fase = new Fase;

	int x, y, w, h, i;
	int n = rand() % 75;
	char str[64];
	ifstream f;

	f.open(path);

	while (!f.eof()) {
		f.getline(str, 64);
		sscanf(str, "%d,%d,%d,%d", &x, &y, &w, &h);
		Plataforma *p = new Plataforma(x, y, w, h);
		_listaPlataformas.colaNoComeco(p);
		f.getline(str, 1);
	}
    for(i = 0 ; i < n ; i++){

        Mumia* m = new Mumia(_jogador1,_jogador2,rand(),rand());
        _listaInimigos.colaNoFinal(m);

    }

	f.close();
}

void Jogo::Desenhar () {

}
