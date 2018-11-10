#include "src/Principal.h"
#include "Jogador.h"

int main () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();
	janela->CriaJanela(sf::VideoMode(Janela::largura, Janela::altura), Janela::titulo);

	Jogador teste;
	sf::Event ev;


	while (1) {
		janela->Limpar();
		janela->SondarEvento(ev);

		teste.Executar();
		teste.Desenhar();

		janela->Atualizar();
	}

	return 0;
}
