#include "Fase.h"

Fase::Fase () {
	_isOver = 0;
}

Fase::~Fase () {
}

void Fase::CarregarFase (char *path) {
	int x, y, w, h;
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

	f.close();
}

void Fase::Executar () {
	GerenciadorGrafico *janela = GerenciadorGrafico::GetInstance();
	GerenciadorDeColisao colisoes;

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
	i_j2.SetKeyAtaque(sf::Keyboard::Num0);

	Jogador j1(&i_j1, 20, 50);
	Jogador j2(&i_j2, 680, 0);

	while (!_isOver) {
		janela->Limpar();
		janela->SondarEvento(ev);

		j1.Executar(janela->GetDeltaTime());
		j2.Executar(janela->GetDeltaTime());

		colisoes.Calcular();

		j1.Desenhar();
		j2.Desenhar();

		janela->Atualizar();
	}
}
