/*
    Chefao da fase do Egito

    Segue os jogadores e atira um ankh neles
*/
#ifndef FARAO_H
#define FARAO_H

#include "../GerenciadorDeTexturas.h"
#include "../GerenciadorGrafico.h"
#include "../Inimigos/Inimigo.h"
#include "../Jogador/Jogador.h"
#include "../common.h"

class Farao: public Inimigo {
    enum class EstadoFarao {
        SeguindoJ1,
        SeguindoJ2,
        Atacando,
        Pulando,
        PulandoParaJ1,
        PulandoParaJ2,
        Esperando,
        Guardando,
    };

    public:

        Farao(Jogador *j1 = NULL, Jogador *j2 = NULL, Lista<Projetil*>* projeteis = NULL, int x = 0, int y = 0);
        ~Farao();

        void Executar (float dt);
        bool PodeMachucar();

    private:
        float _timerDescanso;
        EstadoFarao _estado;

};

#endif //FARAO_H
