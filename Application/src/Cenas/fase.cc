#include"fase.h"

Fase::Fase(){}

Fase::~Fase(){}

void Fase::carregaFase(char* path){

    ifstream f;
    f.open(path);
    int x, y, w, h;
    char* str;
    while(!f.eof()){

        f.getline(str,64);
        sscanf(str, "%d,%d,%d,%d",x,y,w,h);
        Plataforma* p = new Plataforma(x,y,w,h);
        ListaPlataformas.colaNoComeco(p);
        f.getline(str, 1);

    }
    f.close();

}

bool Fase::isOver(){

    return false;

}

void Fase::executar(){

    //Recebe dados do teclado
    //Atualiza a posição dos jogadores
    //Verifica colisão dos jogadores com as plataformas
    //Verifica colisão dos jogadores com os inimigos
    //Verifica colisão dos jogadores com os obstáculos
    //Verifica colisão dos inimigos com as plataformas
    //Verifica colisão dos inimigos com os obstáculos
    //Atualiza as posições dos inimigos
    //Envia para a tela

}
