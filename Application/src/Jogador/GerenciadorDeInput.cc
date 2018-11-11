#include "GerenciadorDeInput.h"

GerenciadorDeInput::GerenciadorDeInput () {
	//ctor
}

GerenciadorDeInput::~GerenciadorDeInput () {
	//dtor
}

void GerenciadorDeInput::SetKeyEsquerda (sf::Keyboard::Key key) {
	_key_esquerda = key;
}

void GerenciadorDeInput::SetKeyDireita (sf::Keyboard::Key key) {
	_key_direita = key;
}

void GerenciadorDeInput::SetKeyPulo (sf::Keyboard::Key key) {
	_key_pulo = key;
}

void GerenciadorDeInput::SetKeyAtaque (sf::Keyboard::Key key) {
	_key_ataque = key;
}

void GerenciadorDeInput::Atualizar () {
	_old_pulo = _pulo;
	_old_ataque = _ataque;

	_esquerda = sf::Keyboard::isKeyPressed(_key_esquerda);
	_direita = sf::Keyboard::isKeyPressed(_key_direita);
	_pulo = sf::Keyboard::isKeyPressed(_key_pulo);
	_ataque = sf::Keyboard::isKeyPressed(_key_ataque);
}

bool GerenciadorDeInput::GetDireita () {
	return _direita;
}

bool GerenciadorDeInput::GetEsquerda () {
	return _esquerda;
}

bool GerenciadorDeInput::GetPulou () {
	return (_pulo && !_old_pulo);
}

bool GerenciadorDeInput::GetPulando () {
	return _pulo;
}

bool GerenciadorDeInput::GetAtacou () {
	return (_ataque && !_old_ataque);
}
