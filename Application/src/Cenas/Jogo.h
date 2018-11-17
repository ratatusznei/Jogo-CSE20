/*
	Possui a fase, camera e jogadores
*/

#ifndef JOGO_H
#define JOGO_H

#include "../GerenciadorGrafico.h"
#include "../Fases/Fase.h"

#include <SFML/System.hpp>
#include <fstream>

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

		/*	IN: Path para um arquivo de fase
		OUT: Preenche as listas de entidades conforme o arquivo */
        void CarregarFase (char* path);

	private:
		Fase* _fase;
		Jogador* _jogador1;
        Jogador* _jogador2;

        GerenciadorDeColisao colisoes;

        Lista<Inimigo*> _listaInimigos;
        Lista<Plataforma*> _listaPlataformas;

};

#endif // JOGO_H
