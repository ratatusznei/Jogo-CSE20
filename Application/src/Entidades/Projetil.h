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

        /*  IN: Nenhum
            OUT: Referencia para a textura */
		sf::Texture* GetTexture ();

		/*  IN: Referencia para uma textura
            OUT: Seta a textura do projetil */
		void SetTexture (sf::Texture *tex);

		/*  IN: Uma velocidade em x
            OUT: Seta a velocidade em x do projetil */
		void SetVelocidade (int vx);

		/*  IN: O dano que o projetil causara
            OUT: Seta o dano do projetil */
		void SetDano (int dano);

		/*  IN: Nenhum
            OUT: O dano causado pelo projetil */
		int GetDano ();

		/*  IN: Nenhum
            OUT: Seta o offSet em y da textura do projetil no arquivo*/
		int GetOffSetY ();

		/*  IN: O offset em y no arquivo da textura
            OUT: Seta o offset*/
		void SetOffSetY (int offset);

		/*  IN: Tempo de vida do projetil
            OUT: Seta o tempo */
		void SetTempoPraMorrer (float t);

		/*  IN: Nenhum
            OUT: O tempo de vida restante do projetil */
		float GetTempoPraMorrer ();

		/*  IN: Nenhum
            OUT: Se o projetil morreu*/
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
