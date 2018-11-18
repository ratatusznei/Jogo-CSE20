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

		void SetTempoPraMorrer (float t);
		float GetTempoPraMorrer ();

		bool GetMorreu ();

		void Desenhar ();
		void Executar (float dt);

		static void ExecutarTodos (float dt);
		static void DesenharTodos ();
		static void Incluir (Projetil* pp);

	private:
		sf::Vector2f _velocidade;
		float _tempoPraMorrer;

		sf::Texture* _texture;

		static Lista<Projetil*> projeteis;
};

#endif // PROJETIL_H
