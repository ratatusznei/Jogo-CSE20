#include "src/Principal.h"

#include "Jogador.h"
#include "src/Entidades/Plataforma.h"

int main () {
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
	i_j2.SetKeyAtaque(sf::Keyboard::M);

	Jogador j1(&i_j1);

	Plataforma p1(0, Janela::altura - 16, 16, 1);
	Plataforma p2(100, Janela::altura - 16 * 4, 3, 2);
	Plataforma p3(300, 50, 4, 35);

	while (1) {
		janela->Limpar();
		janela->SondarEvento(ev);

		j1.Executar();

		if(!j1.ChecarChao(p1))
			if (!j1.ChecarChao(p2))
				j1.ChecarChao(p3);

		if(!j1.ChecarTeto(p1))
			if (!j1.ChecarTeto(p2))
				j1.ChecarTeto(p3);

		if(!j1.ChecarEsquerda(p1))
			if (!j1.ChecarEsquerda(p2))
				j1.ChecarEsquerda(p3);

		if(!j1.ChecarDireita(p1))
			if (!j1.ChecarDireita(p2))
				j1.ChecarDireita(p3);


		p1.Desenhar();
		p2.Desenhar();
		p3.Desenhar();

		j1.Desenhar();

		janela->Atualizar();
	}

	return 0;
}
