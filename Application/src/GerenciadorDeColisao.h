#ifndef DIRETORDECOLISAO_H
#define DIRETORDECOLISAO_H

#include <list>
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
		list<Jogador*> _jogadores;
		list<Inimigo*> _inimigos;
		list<Plataforma*> _plataformas;
};

#endif // DIRETORDECOLISAO_H
