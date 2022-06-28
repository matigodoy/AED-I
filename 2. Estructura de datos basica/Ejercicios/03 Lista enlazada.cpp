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
		bool estaVacia();
		void insertarAdelante(int);
		void insertarUltimo(int);
		void insertarEn(int,int);
		void removerAdelante();
		void removerUltimo();
		void removerEn(int);
		nodo* buscar(int);
		int longitud();
		void invertir();
		void mostrar();
};

Lista::Lista(){
	inicio = NULL;
}

bool Lista::estaVacia(){
	if(inicio==NULL) return true;
	else return false;
}

void Lista::insertarAdelante(int dato){
	nodo* n = new nodo();
	n->dato = dato;
	n->siguiente = inicio;
	inicio = n;
}

void Lista::insertarUltimo(int dato){
	nodo* nuevo=new nodo();
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	if(inicio != NULL){
		nodo* n = inicio;
		while(n->siguiente != NULL){
			n=n->siguiente;
		}
		n->siguiente = nuevo;
	}
	else inicio = nuevo;
}

void Lista::insertarEn(int dato,int donde){
	nodo* nuevo = new nodo();
	nuevo->dato = dato;
	nuevo->siguiente = NULL;
	if(inicio == NULL){
		inicio = nuevo;
	}
	else{
		nodo* n = inicio;
		while(n != NULL && n->dato != donde){
			n = n->siguiente;
		}
		if(n->dato == donde){
			nuevo->siguiente = n->siguiente;
			n->siguiente = nuevo;
		}
		else delete nuevo;
	}
}

void Lista::removerAdelante(){
	if(inicio != NULL){
		nodo* n = inicio;
		inicio = n->siguiente;
		delete n;
	}
}

void Lista::removerUltimo(){
	if(inicio != NULL){
		if(inicio->siguiente == NULL) removerAdelante();
		else{
			nodo* n = inicio;
			while(n->siguiente->siguiente != NULL){
				n = n->siguiente;
			}
			nodo* m = n->siguiente;
			n->siguiente = NULL;
			delete m;
		}
	}
}

void Lista::removerEn(int donde){
	if(inicio==NULL) return;
	else if(inicio->dato == donde) removerAdelante();
	else{
		nodo* n = inicio;
		while(n->siguiente->dato != donde){
			n = n->siguiente;
		}
		nodo* m = n->siguiente;
		n->siguiente = n->siguiente->siguiente;
		delete m;
	}
}

nodo* Lista::buscar(int dato){
	nodo* n = inicio;
	while(n != NULL && n->dato != dato){
		n = n->siguiente;
	}
	return n;
}

int Lista::longitud(){
	nodo* n = inicio;
	int longitud = 0;
	while(n != NULL){
		longitud ++;
		n = n->siguiente;
	}
	return longitud;
}

void Lista::invertir(){
    nodo* aux = inicio;
    nodo* siguienteNodo = NULL;
    nodo* anteriorNodo = NULL;
    while (aux != NULL){
        siguienteNodo = aux->siguiente;
        aux->siguiente = anteriorNodo;
        anteriorNodo = aux;
        aux = siguienteNodo;
    }
    inicio = anteriorNodo;
}

void Lista::mostrar(){
	nodo* n = inicio;
	while(n != NULL){
		cout<<"["<<n->dato<<"] --> ";
		n=n->siguiente;
	}
	cout<<"[Final]"<<endl;
}

int main(){
	Lista l;

	if(l.estaVacia()==1) cout<<"\nSI esta vacia "<<endl;
	else cout<<"\nNO esta vacia "<<endl;
	
	cout<<"\nInsertar Adelante "<<endl;
	l.insertarAdelante(20);
	l.insertarAdelante(40);
	l.insertarAdelante(60);
	l.insertarAdelante(80);
	l.mostrar();
	
	cout<<"\nInsertar Ultimo "<<endl;
	l.insertarUltimo(10);
	l.insertarUltimo(30);
	l.insertarUltimo(50);
	l.mostrar();
	
	if(l.estaVacia()==1) cout<<"\nSI esta vacia "<<endl;
	else cout<<"\nNO esta vacia "<<endl;
	
	cout<<"\nInsertar En "<<endl;
	l.insertarEn(5,10);
	l.mostrar();
	
	cout<<"\nRemover Adelante "<<endl;
	l.removerAdelante();
	l.mostrar();
	
	cout<<"\nRemover Ultimo "<<endl;
	l.removerUltimo();
	l.mostrar();

	cout<<"\nRemover En "<<endl;
	l.removerEn(5);
	l.mostrar();

	cout<<"\nBuscar numero que existe "<<endl;
	if(l.buscar(20)==0)cout<<"Numero no encontrado "<<endl;
	else cout<<"Numero si encontrado: "<<l.buscar(20)->dato<<endl;
	
	nodo* n = l.buscar(1);
	cout<<"\nBuscar numero que no existe "<<endl;
	if(n==0)cout<<"Numero no encontrado "<<endl;
	else cout<<"Numero si encontrado: "<<n->dato<<endl;
	
	cout<<"\nLa longitud de la lista es: "<<l.longitud()<<endl;
	l.mostrar();

	cout<<"\nInvertir Lista "<<endl;
	l.invertir();
	l.mostrar();
	
	return 0;
}

