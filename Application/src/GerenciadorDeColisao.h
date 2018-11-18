/*
	Gerencia o tratamento de colisoes entre conjuntos de objetos

	Gerencia colisoes jogador-plataforma
	Gerencia colisoes jogador-inimigo
	Gerencia colisoes inimigo-plataforma
*/

#ifndef DIRETORDECOLISAO_H
#define DIRETORDECOLISAO_H

#include "LinkedLists.h"
#include "Jogador.h"
#include "Inimigos/Inimigo.h"
#include "Entidades/Plataforma.h"

class GerenciadorDeColisao {
	public:
		GerenciadorDeColisao ();
		~GerenciadorDeColisao ();

		/* 	IN: Objeto para tratar as colisoes
			OUT: Adiciona o objeto nas listas internas */
		void Incluir (Jogador *pj);

		void SetListaInimigos (Lista<Inimigo*>* pLista);
		void SetListaPlataformas (Lista<Plataforma*>* pLista);
		void SetListaProjInimigos (Lista<Projetil*>* pLista);
		void SetListaProjAmigos (Lista<Projetil*>* pLista);

		void Calcular ();

	private:
		Lista<Jogador*> _jogadores;

		Lista<Inimigo*>* _inimigos;
		Lista<Plataforma*>* _plataformas;

		Lista<Projetil*>* _projAmigos;
		Lista<Projetil*>* _projInimigos;
};

#endif // DIRETORDECOLISAO_H
