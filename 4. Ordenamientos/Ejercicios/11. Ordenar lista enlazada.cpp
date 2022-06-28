#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo* siguiente;
};
class Lista{
	private:
		nodo* inicio;
    public:
		Lista();
		~Lista();
        void insertar(int);
        void mostrar();
        void ordenar();
};

Lista::Lista(){
	inicio=NULL;
}

Lista::~Lista(){
    nodo* n = inicio;
    while(n != NULL){
        nodo* aux = n;
        n = aux->siguiente;
		delete aux;
    }
}

void Lista::insertar(int dato){
	nodo* n = new nodo();
	n->dato = dato;
	n->siguiente = inicio;
	inicio = n;
}

void Lista::mostrar(){
	nodo* n = inicio;
	while(n != NULL){
		cout<<"["<<n->dato<<"] --> ";
		n = n->siguiente;
	}
	cout<<"[Final]"<<endl;
}

void Lista::ordenar(){
    bool ordenado = false;
    while(!ordenado){
        nodo* n = inicio;
        nodo* siguiente = n->siguiente;
        ordenado = true;
        while(n != NULL && siguiente != NULL){
            if(n->dato > siguiente->dato){
                swap(n->dato, siguiente->dato);
                ordenado = false;
            }
            n = n->siguiente;
            siguiente = siguiente->siguiente;
        }
    }
}

int main(){
	Lista l;
    
    l.insertar(2);
    l.insertar(3);
    l.insertar(9);
    l.insertar(1);
    l.insertar(7);
    l.insertar(4);

    cout<<"\nAntes de ordenar "<<endl;
    l.mostrar();

    l.ordenar();

    cout<<"\nDespues de ordenar "<<endl;
    l.mostrar();

    return 0;
}