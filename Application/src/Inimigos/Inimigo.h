#ifndef INIMIGO_H
#define INIMIGO_H

#include "../Entidades/Personagem.h"

class Inimigo: public Personagem {
	public:
		Inimigo (float x = 0, float y = 0, string tex_path = "");
		~Inimigo ();

	protected:

};

#endif // INIMIGO_H
