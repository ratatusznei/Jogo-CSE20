#ifndef GERENCIADORGRAFICO_H
#define GERENCIADORGRAFICO_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Menu.h"
#include "Jogo.h"
#include "TelaDeCreditos.h"

#define WINDOW_LENGTH 960
#define WINDOW_HEIGH 540
#define WINDOW_LABEL "Jogo"

using namespace std;

class GerenciadorGrafico {
	public:
		GerenciadorGrafico (sf::VideoMode video_mode, string titulo);
		~GerenciadorGrafico ();

		bool EstaAberta ();
		bool SondarEvento (sf::Event& evento);
		sf::Vector2i GetPosicaoDoMouse ();
		bool GetMouseClick ();

		void Limpa();
		void Atualiza ();

		void Desenha (Menu& menu);
		void Desenha (Jogo& jogo);

	private:
		sf::RenderWindow _window;
		sf::VideoMode _video_mode;
		string _titulo;
};

#endif // GERENCIADORGRAFICO_H
