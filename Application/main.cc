#include "src/Principal.h"
#include "Jogador.h"

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
	Jogador j2(&i_j2);

	while (1) {
		janela->Limpar();
		janela->SondarEvento(ev);

		j1.Executar();
		j2.Executar();

		j1.Desenhar();
		j2.Desenhar();

		janela->Atualizar();
	}

	return 0;
}
