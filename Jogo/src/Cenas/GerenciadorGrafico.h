#ifndef GERENCIADORGRAFICO_H
#define GERENCIADORGRAFICO_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "../common.h"

using namespace std;

class GerenciadorGrafico {
	public:
		static GerenciadorGrafico* GetInstance ();

		~GerenciadorGrafico ();
		void CriaJanela (sf::VideoMode video_mode, string titulo);

		bool EstaAberta();
		bool SondarEvento (sf::Event& evento);
		sf::Vector2i GetPosicaoDoMouse ();
		bool GetMouseClick ();

		void Limpa();
		void Atualiza ();
		void Desenha (sf::Drawable& objeto);

	private:
		GerenciadorGrafico ();
		static GerenciadorGrafico* _instance;

		sf::RenderWindow _window;
		sf::VideoMode _video_mode;
		string _titulo;
};

#endif // GERENCIADORGRAFICO_H
