#ifndef DIRETORDECOLISAO_H
#define DIRETORDECOLISAO_H

#include <list>
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
		list<Jogador*> _jogadores;
		list<Plataforma*> _plataformas;
};

#endif // DIRETORDECOLISAO_H
