#include <iostream>
#include <sstream>
using namespace std;

struct nodo{
	int dato;
	nodo* siguiente;
};
class Cola{
	private:
		nodo* inicio;
		void mostrarRecursivo(nodo*);
	public:
		Cola();
		~Cola();
		bool estaVacia();
		void Encolar(int);
		void Desencolar();
		int longitud();
		void Leer();
};

Cola::Cola(){
	inicio=NULL;
}

Cola::~Cola(){
    nodo* n = inicio;
    while(n != NULL){
        nodo* aux = n;
        n = aux->siguiente;
		delete aux;
    }
}

bool Cola::estaVacia(){
	if(inicio == NULL){
		return true;
	}
	else{
		return false;
	}
}

void Cola::Encolar(int dato){
	nodo* n = new nodo();
	n->dato = dato;
	n->siguiente = inicio;
	inicio = n;
}

void Cola::Desencolar(){
	if(inicio != NULL){
		if(inicio->siguiente == NULL){
			nodo* n = inicio;
			inicio = n->siguiente;
			delete n;
		}
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

int Cola::longitud(){
	nodo* n = inicio;
	int longitud = 0;
	while (n != NULL){
		longitud ++;
		n = n->siguiente;
	}
	return longitud;
}

void Cola::Leer(){
	nodo* n = inicio;
    cout<<"\nCOLA: ";
	while(n != NULL){
		cout<<"["<<n->dato<<"] | ";
		n = n->siguiente;
	}
}

int main(){
	Cola l;
	
	if(l.estaVacia()==1) cout<<"\nSI esta vacia "<<endl;
	else cout<<"\nNO esta vacia "<<endl;
	
	cout<<"\nEncolar "<<endl;
	l.Encolar(20);
	l.Encolar(40);
	l.Encolar(60);
	l.Leer();
	
	if(l.estaVacia()==1) cout<<"\nSI esta vacia "<<endl;
	else cout<<"\nNO esta vacia "<<endl;
	
	cout<<"\nDesencolar "<<endl;
	l.Desencolar();
	l.Leer();
	
	cout<<"\nLa longitud de la cola es: "<<l.longitud()<<endl;
	
	return 0;
}
