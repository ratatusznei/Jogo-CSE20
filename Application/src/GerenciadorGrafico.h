/*
	Um wrapper da interface do SFML

	Singleton
*/

#ifndef GERENCIADORGRAFICO_H
#define GERENCIADORGRAFICO_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "../common.h"

using namespace std;

class GerenciadorGrafico {
	public:
		/* 	IN: Nenhum
			OUT: Ponteiro para a instancia unica da classe */
		static GerenciadorGrafico* GetInstance ();

		~GerenciadorGrafico ();

		/*	IN: Resolucao e titulo da janela grafica
			OUT: Cria a janela do programa */
		void CriaJanela (sf::VideoMode video_mode, string titulo);

		/*	IN: Nenhum
			OUT: Verdadeiro se janela aberta, falso caso contrario */
		bool EstaAberta ();

		/*	IN: Referencia para um evento do SFML
			OUT: Preenche a varivel recebida por referencia com os dados do proximo evento SFML da poll */
		bool SondarEvento (sf::Event& evento);

		/*	IN: Nenhum
			OUT: Vetor SFML com a posicao do mouse relativa ao TOPO-ESQUERDO da janela */
		sf::Vector2i GetPosicaoDoMouse ();

		/*	IN: Nenhum
			OUT: Retorna verdadeiro se o botao esquerdo do mouse esta pressionado */
		bool GetMouseClick ();

		/*	IN: Nenhum
			OUT: Retorna o tempo decorrido na ultima frame, em segundos */
		float GetDeltaTime ();

		/*  IN: Posicao da camera em X
            OUT: Posiciona a camera em X */
		void SetCamera (int x);

		/*  IN: Nenhum
            OUT: Posiciona a camera na origem */
		void ResetCamera ();

		/*	IN: Nenhum
			OUT: Apaga todos os graficos na janela */
		void Limpar ();

		/*	IN: Nenhum
			OUT: Atualiza os graficos desenhados desde a ultima chamada */
		void Atualizar ();

		/*	IN: Um objeto desenhavel SFML
			OUT: Desenha o objeto na tela, eh necessario Atualizar a janela depois */
		void Desenhar (sf::Drawable& objeto);

	private:
		GerenciadorGrafico ();
		static GerenciadorGrafico* _instance;

		sf::Clock _timer;
		float _deltaT;

		sf::View _camera;

		sf::RenderWindow _window;
		sf::VideoMode _videoMode;
		string _titulo;
};

#endif // GERENCIADORGRAFICO_H
