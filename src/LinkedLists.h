#ifndef LINKEDLISTS_H_INCLUDED
#define LINKEDLISTS_H_INCLUDED

//Listas duplas

/**
Funções de linkedlists.h:
	colaNoComeco(a: T) : void
		Inclui um novo elemento no começo da lista e define 'a' como informação.

	colaNoFinal(a: T) : void
		Inclui um novo elemento no final da lista e define 'a' como informação.

	tiraDoComeco(void) : int
		Remove um elemento do começo da lista.
		Retorna 1 se a lista estiver vazia.

	tiraDoFinal(void) : int
		Remove um elemento do final da lista.
		Retorna 1 se a lista estiver vazia.

	goToTop(void) : void
		Coloca o ponteiro da lista no topo.

	goToBottom(void) : void
		Coloca o ponteiro da lista no fundo.

	getWhatIsHere(void) : T1
		Retorna a informação armazenada na posição da lista apontadapelo ponteiro.

	removeWhatIsHere(void) : void
		Remove o elemento apontado pelo ponteiro.

	mataLista(void) : void
		Esvazia a lista.

Operadores:
	operator ++ : int
		Ponteiro da lista aponta para o próximo elemento.
		Retorna 1 se estiver no fundo da lista.

	operator -- : int
		Ponteiro da lista aponta para o elemento anterior.
		Retorna 1 se estiver no topo da lista.

	operator += : void
		Adiciona um dado no final da lista.

	operator -= : void
		Adiciona um dado no começo da lista.
*/

#include<stdlib.h>

/******************************************************************************/

template <typename T1>
class Lista{

private:

	template <typename T2>
	class Node{

	private:

		T2 data;        //Dado a ser armazenado
		Node<T2>* ante; //Ponteiro para o anterior da lista
		Node<T2>* prox; //Ponteiro para o próximo da lista

	public:
		Node(){     //Construtora
			ante = NULL;
			prox = NULL;
		}
		~Node(){    //Destrutora
			ante = NULL;
			prox = NULL;
		}

	void setDataValue(const T2 a){  //Recebe o dado
		data = a;
	}
	T2 getDataValue(){        //Retorna o dado
		return data;
	}

	void setAnteLista(Node<T2>* no){//Define o elemento anterior da lista
		ante = no;
	}

	Node<T2>* getAnteLista(){       //Retorna o ponteiro para o anterior da lista
		return ante;
	}

	void setProxLista(Node<T2>* no){//Define o próximo elemento da lista
		prox = no;
	}

	Node<T2>* getProxLista(){       //Retorna o ponteiro para o próximo da lista
		return prox;
	}
};

private:
	Node<T1>* top;   //Topo da lista
	Node<T1>* here;  //Posição atual da lista
	Node<T1>* bottom;//Fundo da lista

public:
	Lista(){    //Construtora
		top = NULL;
		here = top;
		bottom = NULL;
	}
	~Lista(){   //Destrutora
		mataLista();
		top = NULL;
		here = NULL;
		bottom = NULL;
	}

	bool estaVazia () {
		return (top == NULL) && (bottom == NULL);
	}

	void colaNoComeco(T1 a){
		Node<T1>* no = (Node<T1>*) malloc(sizeof(Node<T1>));  //Cria um nó novo

		if(top == NULL && bottom == NULL){    //Se a lista estiver vazia
			no->setProxLista(NULL);//Como só tem ele, não aponta para frente
			no->setAnteLista(NULL);//Nem para trás
			no->setDataValue(a);   //Recebe o dado
			top = no;              //O novo nó se torna o topo da lista
			bottom = no;           //O novo nó também se torna o fundo da lista
		}
		else{
			Node<T1>* aux = here;
			here = top;             //Atual recebe o topo da lista
			no->setProxLista(here); //O antigo topo se torna o próximo do novo topo
			no->setAnteLista(NULL); //Como é o topo, anterior aponta para NULL
			no->setDataValue(a);    //Recebe o dado
			here->setAnteLista(no); //Antigo topo aponta para trás para o novo topo
			top = no;               //Substitui o topo da lista pelo nó novo
			here = aux;
		}
	}

	void colaNoFinal (T1 a){
		Node<T1>* no = (Node<T1>*) malloc(sizeof(Node<T1>));  //Cria um nó novo

		if(top == NULL && bottom == NULL){     //Se a lista estiver vazia
			no->setProxLista(NULL);//Como só tem ele, não aponta para frente
			no->setAnteLista(NULL);//Nem para trás
			no->setDataValue(a);   //Recebe o dado
			top = no;              //O novo nó se torna o topo da lista
			bottom = no;           //O novo nó também se torna o fundo da lista
		}
		else{
			Node<T1>* aux = here;
			here = bottom;         //Atual recebe o fundo da lista
			no->setAnteLista(here);//O antigo fundo se torna o anterior do nó novo
			no->setProxLista(NULL);//Como é o fundo, próximo aponta para NULL
			no->setDataValue(a);   //Recebe o dado
			here->setProxLista(no);//Antigo fundo aponta para frente para o novo fundo
			bottom = no;           //Substitui o fundo da lista pelo nó novo
			here = aux;
		}
	}

	int tiraDoComeco (){ //Retorna 1 se a lista estiver vazia
		if(top == NULL){
			return 1;
		}
		else{
			Node<T1>* aux = here;
			here = top;                 //Recebe o primeiro elemento da lista
			top = top->getProxLista();  //O segundo elemento se torna o novo primeiro
			top->setAnteLista(NULL);    //O primeiro aponta para NULL
			free(here);                 //Destroi o antigo primeiro
			here = aux;
			return 0;
		}
	}

	int tiraDoFinal (){ //Retorna 1 se a lista estiver vazia
		if(top == NULL){
			return 1;
		}
		else{
			Node<T1>* aux = here;
			here = bottom;                  //Recebe o último elemento da lista
			bottom = bottom->getAnteLista();//O penúltimo elemento se torna o novo último
			bottom->setProxLista(NULL);     //O último elemento aponta pra NULL
			free(here);                     //Destroi o antigo último
			here = aux;
			return 0;
		}
	}

	int operator ++ (){
		if(here == bottom){
			return 1;
		}
		else{
			if (here != NULL) {
				here = here->getProxLista();
				return 0;
			}
			else {
				return 1;
			}
		}
	}

	int operator -- (){
		if(here == top){
			return 1;
		}
		else{
			if (here != NULL) {
				here = here->getAnteLista();
				return 0;
			}
			else {
				return 1;
			}
		}
	}

	void operator += (T1 n){
		colaNoFinal(n);
	}

	void operator -= (T1 n){
		colaNoComeco(n);
	}

	void goToTop(){
		here = top;
	}

	void goToBottom(){
		here = bottom;
	}

	T1 getWhatIsHere(){
		if (here != NULL) {
			return here->getDataValue();
		}

		return NULL;
	}

	void removeWhatIsHere(){
		Node<T1>* aux1 = here->getAnteLista();
		Node<T1>* aux2 = here->getProxLista();
		free(here);

		if (aux1 != NULL){
			aux1->setProxLista(aux2);
		}
		else {
			top = aux2;
		}

		if (aux2 != NULL) {
			aux2->setAnteLista(aux1);
		}
		else {
			bottom = aux1;
		}

		here = aux2;
	}

	void mataLista(){   //Destroi a lista
		if (here != NULL) {
			here = top->getProxLista();     //Define o atual como o segundo elemento

			while (here != NULL){            //Enquanto não estiver no final da lista
				free(top);                  //Libera o topo
				top = here;                 //Desloca o topo uma posição para frente
				here = top->getProxLista(); //Desloca o atual uma posição para frente
			}//Enquanto não estiver no final da lista, vai destruindo ela

			free(top);      //Quando chegar no final, destroi o final
			here = NULL;    //Aterra o atual
			top = NULL;
		}
	}
};

#endif // LINKEDLISTS_H_INCLUDED
