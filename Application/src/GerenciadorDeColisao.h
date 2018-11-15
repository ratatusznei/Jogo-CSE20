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

		void Incluir (Jogador *pj);
		void Incluir (Inimigo *pi);
		void Incluir (Plataforma *pp);

		void Calcular ();

	private:
		Lista<Jogador*> _jogadores;
		Lista<Inimigo*> _inimigos;
		Lista<Plataforma*> _plataformas;
};

#endif // DIRETORDECOLISAO_H
