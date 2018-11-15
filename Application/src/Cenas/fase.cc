#include"fase.h"

Fase::Fase(){

    isOver = 0;

}

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

void Fase::executar(){

    GerenciadorDeColisao colisoes;

    sf::Event ev;

    GerenciadorDeInput i_j1;
    i_j1.SetKeyEsquerda(sf::Keyboard::A);
    i_j1.SetKeyDireita(sf::Keyboard::D);
    i_j1.SetKeyPulo(sf::Keyboard::W);
    i_j1.SetKeyAtaque(sf::Keyboard::Space);

    GerenciadorDeInput i_j2;
    i_j2.SetKeyEsquerda(sf::Keyboard::Left);
    i_j2.SetKeyDireita(sf::Keyboard::Right);
    i_j2.SetKeyPulo(sf::Keyboard::Up);
    i_j2.SetKeyAtaque(sf::Keyboard::M);

    Jogador j1(&i_j1);
    Jogador j2(&i_j2);

    while(!isOver){

        janela->Limpar();
        janela->SondarEvento(ev);

        j1.Executar();
        j2.Executar();

        colisoes.Calcular();

        p1.Desenhar();
        p2.Desenhar();
        p3.Desenhar();
        p4.Desenhar();

        j1.Desenhar();
        j2.Desenhar();

        janela->Atualizar();

    }

}
