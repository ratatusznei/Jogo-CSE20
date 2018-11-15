#ifndef DIRETORDECOLISAO_H
#define DIRETORDECOLISAO_H

#include "linkedlists.h"
#include "Jogador.h"
#include "Entidades/Plataforma.h"

class DiretorDeColisao {
	public:
		DiretorDeColisao ();
		~DiretorDeColisao ();

		void Incluir (Jogador *pj);
		void Incluir (Plataforma *pp);

		void Calcular ();

	private:
		Lista<Jogador*> _jogadores;
		Lista<Plataforma*> _plataformas;
};

#endif // DIRETORDECOLISAO_H
