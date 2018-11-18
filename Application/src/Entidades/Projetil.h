#ifndef PROJETIL_H
#define PROJETIL_H

#include "Entidade.h"
#include "../LinkedLists.h"
#include "../common.h"

class Projetil: public Entidade {
	public:
		Projetil();
		Projetil(Projetil& prototipo, int x, int y, int vx, int vy);
		virtual ~Projetil();

		sf::Texture* GetTexture ();
		void SetTexture (sf::Texture *tex);

		void SetVelocidade (int vx);

		void SetDano (int dano);
		int GetDano ();

		int GetOffSetY ();
		void SetOffSetY (int offset);

		void SetTempoPraMorrer (float t);
		float GetTempoPraMorrer ();

		bool GetMorreu ();

		void Desenhar ();
		void Executar (float dt);

	private:
		sf::Vector2f _velocidade;
		float _tempoPraMorrer;

		int _dano;

		int _offSetY;
		sf::Texture* _texture;
};

#endif // PROJETIL_H
