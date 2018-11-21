/*
	Classe pai dos inimigos
*/

#ifndef INIMIGO_H
#define INIMIGO_H

#include "../Entidades/Personagem.h"
#include "../Jogador/Jogador.h"

class Inimigo: public Personagem {
	public:
		Inimigo (float x = 0, float y = 0, Lista<Projetil*>* projeteis = NULL, int n_animacoes = 1);
		~Inimigo ();

		/*	IN: O delta tempo da ultima frame
			OUT: Calcula novas propriedades do inimigo */
		virtual void Executar(float dt) = 0;

		/*	IN: Nenhum
			OUT: retorna o valor correspondente ao tipo de inimigo */
		int QualTipo();

		/*  IN: Nenhum
            OUT: Verdadeiro se o inimigo pode ser machucado */
		virtual bool PodeMachucar();

	protected:
        Jogador *_j1;
		Jogador *_j2;

		int _x0;
		float _range;
		float _rangeAtaque;

	    int _tipo;

};

#endif // INIMIGO_H
