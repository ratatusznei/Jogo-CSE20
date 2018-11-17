#include "Fase.h"

Fase::Fase () {

    janela = GerenciadorGrafico::GetInstance();
	_isOver = 0;

}

Fase::~Fase () {
}

bool Fase::Executar (Jogador* j1, Jogador* j2, Lista<Inimigo*>* li,
                     Lista<Plataforma*>* lp, GerenciadorDeColisao* colisoes){

    float dt = janela->GetDeltaTime();

    sf::Event ev;

    janela->Limpar();
    janela->SondarEvento(ev);

    j1->Executar(dt);
    j2->Executar(dt);

    li->goToTop();
    do{
        li->getWhatIsHere()->Executar(dt);
    }
    while(!(++li));

    colisoes->Calcular();

    return _isOver;

}
