#include "src/Principal.h"

#include "Jogador.h"
#include "src/Entidades/Plataforma.h"
#include "src/GerenciadorDeColisao.h"
#include "src/Inimigos/Mumia.h"

int __main () {
	Principal p;
	p.Executar();
	return 0;
}

int main () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();
	janela->CriaJanela(sf::VideoMode(Janela::largura, Janela::altura), Janela::titulo);

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
	i_j2.SetKeyAtaque(sf::Keyboard::RShift);

	Jogador j1(&i_j1, 20, 50);
	Jogador j2(&i_j2, 680, 0);

	j1.IniciarRobo();
	j2.IniciarDoctor();

	Plataforma p1(0, Janela::altura - 16, 16, 1);
	Plataforma p2(70, Janela::altura - 16 * 4, 3, 1);
	Plataforma p3(700, 50, 4, 6);
	Plataforma p4(200, Janela::altura - 16 * 8, 3, 1);

	Mumia m1(&j1, &j2, 380, 50);

	colisoes.Incluir(&j1);
	colisoes.Incluir(&j2);

	colisoes.Incluir(&m1);

	colisoes.Incluir(&p1);
	colisoes.Incluir(&p2);
	colisoes.Incluir(&p3);
	colisoes.Incluir(&p4);

	sf::Texture t_fundo;
	t_fundo.loadFromFile("res/sprites/egypt_backg.png");

	sf::Sprite fundo(t_fundo);
	fundo.setScale(2, 2);

	while (1) {
		float dt = janela->GetDeltaTime();

		janela->Limpar();
		janela->SondarEvento(ev);

		j1.Executar(dt);
		j2.Executar(dt);

		m1.Executar(dt);

		colisoes.Calcular();

		janela->Desenhar(fundo);

		p1.Desenhar();
		p2.Desenhar();
		p3.Desenhar();
		p4.Desenhar();

		j1.Desenhar();
		j2.Desenhar();
		m1.Desenhar();

		janela->Atualizar();
	}

	return 0;
}
