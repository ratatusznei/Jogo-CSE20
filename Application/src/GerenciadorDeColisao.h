#ifndef DIRETORDECOLISAO_H
#define DIRETORDECOLISAO_H

#include "../../include/linkedlists.h"
#include "Jogador.h"
#include "Inimigos/Mumia.h"
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
