/*
	Classe pai dos inimigos
*/

#ifndef INIMIGO_H
#define INIMIGO_H

#include "../Entidades/Personagem.h"

class Inimigo: public Personagem {
	public:
		Inimigo (float x = 0, float y = 0, string tex_path = "", int n_animacoes = 1);
		~Inimigo ();

		/*	IN: O delta tempo da ultima frame
			OUT: Calcula novas propriedades do inimigo */
		virtual void Executar(float dt) = 0;

		/*	IN: void
			OUT: retorna o valor correspondente ao tipo de inimigo */
		int QualTipo();

	protected:

	    int _tipo;

};

#endif // INIMIGO_H
