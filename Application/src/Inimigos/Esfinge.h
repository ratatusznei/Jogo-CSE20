/*

    Chefao da fase do Egito
    Se tem um jogador no seu alcance, ataca
    Se não, ele pula, dando dano em área
    
*/
#ifndef ESFINGE_H
#define ESFINGE_H

#include "../GerenciadorDeTexturas.h"
#include "../GerenciadorGrafico.h"
#include "../Inimigos/Inimigo.h"
#include "../Jogador/Jogador.h"
#include "../common.h"

class Esfinge: public Inimigo{
    
    enum class EstadoEsfinge {
	Atacando,
	Pulando,
        Esperando,
	Guardando,
    };
    
    public:
        
        Esfinge(Jogador *j1 = NULL, Jogador *j2 = NULL, Lista<Projetil*>* projeteis = NULL, int x = 0, int y = 0);
	~Esfinge();

	void Executar (float dt);

    private:
    
        Jogador *_j1;
	Jogador *_j2;

	int _x0;
	float _range;
	float _range_ataque;
	float _range_dist;

        EstadoEsfinge _estado;

};

#endif //ESFINGE_H
