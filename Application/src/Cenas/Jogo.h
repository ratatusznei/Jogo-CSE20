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

		void Iniciar (bool ehCoop);
		bool GameOver ();

	private:
		Fase* _faseAtual;

		bool _coop;
		bool _acabou;

		int _camera_x;

		Jogador _jogador1;
		Jogador _jogador2;
		GerenciadorDeInput _in_j1;
		GerenciadorDeInput _in_j2;

		sf::Texture _tex_fundo;
		sf::Sprite _sp_fundo;

		GerenciadorDeColisao _colisoes;

		Lista<Projetil*> _listaProjAmigos;
		Lista<Projetil*> _listaProjInimigos;

		Lista<Inimigo*> _listaInimigos;
		Lista<Plataforma*> _listaPlataformas;

		void CarregarFase (Fase *pFase);
};

#endif // JOGO_H
