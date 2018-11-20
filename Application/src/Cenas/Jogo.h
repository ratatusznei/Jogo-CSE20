/*
	Possui a fase e jogadores
*/

#ifndef JOGO_H
#define JOGO_H

#include <SFML/System.hpp>
#include <fstream>

#include "../GerenciadorGrafico.h"
#include "../Fases/Fase.h"
#include "../Fases/FaseEgito.h"

#include "../GerenciadorGrafico.h"
#include "../GerenciadorDeColisao.h"
#include "../LinkedLists.h"

#include "../Jogador/Jogador.h"
#include "../Inimigos/Mumia.h"
#include "../Entidades/Plataforma.h"

class Jogo {
	public:
		Jogo ();
		~Jogo ();

		void Executar ();
		void Desenhar ();

		/*  IN: Verdadeiro se dois jogadores, falso se um jogador
            OUT: Inicia o jogo, carregando a 1a fase */
		void Iniciar (bool ehCoop);

		/*  IN: Nenhum
            OUT: Verdadeiro se o jogo acabou */
		bool GameOver ();

		/*  IN: Nenhum
            OUT: Altera o estado do jogo de pausado para rodando ou de rodando para pausado */
		void TogglePausa ();

	private:
		Fase* _faseAtual;

		bool _coop;
		bool _acabou;

		int _cameraX;

		Jogador _jogador1;
		Jogador _jogador2;
		GerenciadorDeInput _inJ1;
		GerenciadorDeInput _inJ2;

		sf::Texture _texFundo;
		sf::Sprite _spFundo;

		GerenciadorDeColisao _colisoes;

		Lista<Projetil*> _listaProjAmigos;
		Lista<Projetil*> _listaProjInimigos;

		Lista<Inimigo*> _listaInimigos;
		Lista<Plataforma*> _listaPlataformas;

		bool _estaPausado;
		sf::Font _fontePausado;
		sf::Text _textoPausado;

		void CarregarFase (Fase *pFase);
};

#endif // JOGO_H
