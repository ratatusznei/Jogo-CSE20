/*
    Anima as sprites

    Recebe o objeto sprite e anima suas texturas
*/

#ifndef ANIMADOR_H
#define ANIMADOR_H

#include <SFML/Graphics.hpp>
#include "common.h"

class Animador {
	public:
		Animador(int n_animacoes);
		~Animador();

        /*  IN: Tempo decorrido na ultima frame
            OUT: Atualiza os contadores internos e as sprites */
		void Executar (float dt);

		/*  IN: Indice da animacao
            OUT: Executa a animacao correspondente ao indice */
		void Play (int indice);

		/*  IN: Nenhum
            OUT: Reinicia a animacao que esta rodando */
		void Restart ();

		/*  IN: Indice da animacao, numero de quadros na animacao
            OUT: Seta o numero de quadros para a respectiva animacao */
		void SetFrameCount (int indice, int count);

		/*  IN: Tamanho do quadro da animacao na textura
            OUT: Seta o tamanho do quadro */
		void SetTamanhoQuadro (int tamanho);

		/*  IN: OffSet em y no arquivo de textura onde comeca a animacao
            OUT: Set o offset */
		void SetOffSetY (int offset);

		/*  IN: O periodo de tempo, em segundos, entre cada mudanca de quadro
            OUT: Seta o periodo	*/
		void SetPeriodo (float t);

		/*  IN: Referencias para a caixa de textura e a sprite que serao animadas
            OUT: Seta a caixa e a sprite */
		void SetTextureBox (sf::IntRect* tex_rect);
		void SetSprite (sf::Sprite* sprite);

		/*  IN: Bool que indica se a animacao deve se repetir
            OUT: Seta a flag de repeticao */
		void SetLoop (bool do_loop);

		/*  IN: Nenhum
            OUT: Verdadeiro se a animacao foi completada, falso caso esteja sendo executada ainda */
		bool GetTerminou ();

	private:
		// Ponteiro de vetor alocado dinamicamente, o vetor contem o numero de quadros de cada animacao
		int *_maxFrames;
		int _nAnims;

		int _animAtual;
		int _quadroAtual;

		int _tamanho;
		int _offSetY;

		bool _ehLoop;
		bool _terminou;

		float _periodo;
		float _timer;

		sf::IntRect* _texRect;
		sf::Sprite* _sp;
};

#endif // ANIMADOR_H
