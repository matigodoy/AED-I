#include <iostream>
#include <sstream>
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
		void insertar(int);
		void mostrar();
        nodo* getInicio();
        bool sonIguales(nodo*);
};

Lista::Lista(){
	inicio = NULL;
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
		n=n->siguiente;
	}
	cout<<"[Final]"<<endl;
}

nodo* Lista::getInicio(){
    return inicio;
}

bool Lista::sonIguales(nodo* ini){
    nodo* m = inicio;
    nodo* n = ini;
    while(n != NULL && m != NULL){
        if(n->dato != m->dato) return false;
        else{
            n = n->siguiente;
            m = m->siguiente;
        }
    }
    return true;
}

int main(){
    Lista l1;
    Lista l2;

    l1.insertar(10);
    l1.insertar(20);
    l1.insertar(30);
    l1.insertar(40);
    l1.insertar(50);
    cout<<"Mostar lista 1 "<<endl;
    l1.mostrar();

    l2.insertar(10);
    l2.insertar(20);
    l2.insertar(30);
    l2.insertar(40);
    l2.insertar(50);
    cout<<"Mostar lista 2 "<<endl;
    l2.mostrar();

    if(l1.sonIguales(l2.getInicio()) == true) cout<<"Las listas son iguales "<<endl;
    else cout<<"Las listas son diferentes "<<endl;
}