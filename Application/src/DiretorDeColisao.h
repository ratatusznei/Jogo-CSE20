#ifndef DIRETORDECOLISAO_H
#define DIRETORDECOLISAO_H

#include <list>
#include "Jogador.h"
#include "Inimigos/Mumia.h"
#include "Entidades/Plataforma.h"

class DiretorDeColisao {
	public:
		DiretorDeColisao ();
		~DiretorDeColisao ();

		void Incluir (Jogador *pj);
		void Incluir (Mumia *pi);
		void Incluir (Plataforma *pp);

		void Calcular ();

	private:
		list<Jogador*> _jogadores;
		list<Mumia*> _inimigos;
		list<Plataforma*> _plataformas;
};

#endif // DIRETORDECOLISAO_H
