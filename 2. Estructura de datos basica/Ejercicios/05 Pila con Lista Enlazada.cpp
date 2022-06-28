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
		~Lista();
		bool estaVacia();
		void Apilar(int);
		void Leer();
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

bool Lista::estaVacia(){
	if(inicio == NULL) return true;
	else return false;
}

void Lista::Apilar(int dato){
	nodo* n = new nodo();
	n->dato = dato;
	n->siguiente = inicio;
	inicio = n;
}

void Lista::Leer(){
	nodo* n = inicio;
    cout<<"Pila"<<endl;
    cout<<"-----"<<endl;
	while(n != NULL){
		cout<<"["<<n->dato<<"]"<<endl;
        cout<<"-----"<<endl;
		n = n->siguiente;
	}
}

int main(){
	Lista l;
	
	if(l.estaVacia()==1) cout<<"\nSI esta vacia "<<endl;
	else cout<<"\nNO esta vacia "<<endl;
	
	cout<<"\nApilar "<<endl;
	l.Apilar(20);
	l.Apilar(40);
	l.Apilar(60);
	l.Apilar(80);
	l.Leer();
	
	if(l.estaVacia()==1) cout<<"\nSI esta vacia "<<endl;
	else cout<<"\nNO esta vacia "<<endl;
	
	l.Leer();

	return 0;
}

