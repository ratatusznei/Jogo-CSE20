#include "TelaDeCreditos.h"

TelaDeCreditos::TelaDeCreditos ():
_disciplina(""),
_professor("")
{
}

TelaDeCreditos::~TelaDeCreditos () {
	//dtor
}

void TelaDeCreditos::SetCriadores (string criador0, string criador1) {
	_criadores[0] = criador0;
	_criadores[1] = criador1;
}

void TelaDeCreditos::SetDisciplina (string disciplina) {
	_disciplina = disciplina;
}

void TelaDeCreditos::SetProfessor (string professor) {
	_professor = professor;
}

void TelaDeCreditos::Executa () {
}
