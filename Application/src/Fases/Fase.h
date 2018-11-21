/*
	Classe que representa fases

	Possui referencias para os jogadores
*/


#ifndef FASE_H
#define FASE_H

#include <SFML/System.hpp>
#include <fstream>

#include "../GerenciadorGrafico.h"
#include "../GerenciadorDeColisao.h"
#include "../LinkedLists.h"

#include "../Jogador/Jogador.h"
#include "../Inimigos/Inimigo.h"
#include "../Entidades/Plataforma.h"

class Fase {
	public:
		Fase (Jogador *j1, Jogador* j2);
		virtual ~Fase ();

		/*  IN: Nenhum
            OUT: A referencia para a proxima fase, ou NULL caso nao tenha proxima fase */
		virtual Fase* CarregaProximaFase () = 0;

		/*  IN: Nenhum
            OUT: Verdadeiro se o objetivo foi concluido */
		virtual bool ChecarObjetivo () = 0;

		/*  IN: Nenhum
            OUT: Inicializa as propriedades pertinentes dos jogadores para o inicio da fase */
		virtual void CarregaJogadores () = 0;

		/*  IN: Referencias para lista de inimigos e lista de projeteis inimigos
            OUT: Preenche a lista com um numero aleatorio de inimigos conforme os spawns da fase */
		virtual void CarregaInimigos (Lista<Inimigo*>* _pLista, Lista<Projetil*>* projeteis) = 0;

		/*  IN: Referenca para a lista de plataformas
            OUT: Preenche a lista com as plataformas da fase */
		virtual void CarregaPlataformas (Lista<Plataforma*>* _pLista) = 0;

	protected:
		Jogador* _j1;
		Jogador* _j2;
};

#endif // FASE_H
