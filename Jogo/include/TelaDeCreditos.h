#ifndef TELADECREDITOS_H
#define TELADECREDITOS_H

#include <string>

using namespace std;

class TelaDeCreditos {
	public:
		TelaDeCreditos ();
		~TelaDeCreditos ();

		void SetCriadores (string criador0, string criador1);
		void SetDisciplina (string disciplina);
                void SetProfessor (string professor);

		void Executa ();

	protected:

	private:
		string _criadores[2];
		string _disciplina;
		string _professor;
};

#endif // TELADECREDITOS_H
