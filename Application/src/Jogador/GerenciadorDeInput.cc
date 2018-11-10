#include "GerenciadorDeInput.h"

GerenciadorDeInput::GerenciadorDeInput () {
	//ctor
}

GerenciadorDeInput::~GerenciadorDeInput () {
	//dtor
}

bool GerenciadorDeInput::GetDireita () {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

bool GerenciadorDeInput::GetEsquerda () {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}

bool GerenciadorDeInput::GetPulo () {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

bool GerenciadorDeInput::GetAtaque () {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}
