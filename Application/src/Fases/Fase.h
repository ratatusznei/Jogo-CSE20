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

		virtual Fase* CarregaProximaFase () = 0;
		virtual bool ChecarObjetivo () = 0;
		virtual void CarregaJogadores () = 0;
		virtual void CarregaInimigos (Lista<Inimigo*>* _pLista, Lista<Projetil*>* projeteis) = 0;
		virtual void CarregaPlataformas (Lista<Plataforma*>* _pLista) = 0;

	protected:
		Jogador* _j1;
		Jogador* _j2;
};

#endif // FASE_H
