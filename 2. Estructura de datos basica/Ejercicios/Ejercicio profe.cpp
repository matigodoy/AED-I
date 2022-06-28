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
        void mostrarRecursivo(nodo* n);
    public:
        Lista();
        ~Lista();
        void agregarNodo(int);
        void remover();
        void mostrar();
        void insertarUltimo(int);
        nodo* buscar(int);
        int longitud();
        void mostrarRecursivo();
        // int longitudRecursiva();
        // void invertir();
        
};

// Implementaci�n de los m�todos de Lista
Lista::Lista(){
    inicio = NULL;
}

// Lista::~Lista(){
//     nodo *n=this->inicio,*siguiente=NULL;
//     while(n!=NULL)
//     {
//         siguiente=n->siguiente;
//         delete n;
//         n=siguiente;
//     }
// }

Lista::~Lista(){
    nodo* n = inicio;
    while(n){
        nodo* aux = n;
        n = aux->siguiente;
        delete aux;
    }
}

nodo* Lista::buscar(int dato){
    nodo* n = inicio;
    while (n != NULL && n->dato != dato){
        n  = n->siguiente;
    }
    return n;

}

void Lista::agregarNodo(int dato){
    nodo* n = new nodo();
    n->dato = dato;
    n->siguiente = inicio;
    inicio = n;
}

void Lista::remover(){
    if(inicio != NULL){
        nodo* n = inicio;
        inicio = n->siguiente;
        delete n;
    }
}

void Lista::mostrar(){
    nodo* n = inicio;
    while (n != NULL){
        cout << "[" << n->dato << "] --> ";
        n = n->siguiente;
    }
    cout << "[FIN]" << endl;
}

void Lista::insertarUltimo(int m_dato){

    // Creamos el nuevo nodo    
    nodo*nuevoNodo = new nodo;   
    nuevoNodo->dato = m_dato;  
    nuevoNodo->siguiente = NULL;

    // Si la lista no est� vac�a
     if(inicio != NULL){     
        // Buscamos el final de la lista
        nodo* nodoActual = inicio; 
        while(nodoActual->siguiente != NULL){
            nodoActual = nodoActual->siguiente;        
        }
        nodoActual->siguiente = nuevoNodo;               
     }
     else{
        inicio = nuevoNodo; 
     }
}

int Lista::longitud()
{
    nodo* n = inicio;
    int longitud=0;
    while (n!=NULL){
        longitud++;
        n=n->siguiente;
    }
    return longitud;
}

void Lista::mostrarRecursivo(nodo* n){
    if (n != NULL){
        cout << "[" << n->dato << "]-->";
        mostrarRecursivo(n->siguiente);
    }
    return;
}


void Lista::mostrarRecursivo(){
    mostrarRecursivo(inicio);
    cout << "[FIN REC]" << endl;
}


int main(){

    Lista l;
    l.insertarUltimo(98);
    l.agregarNodo(5);
    l.agregarNodo(21);
    l.agregarNodo(34);
    cout << "Longitud de la lista: " << l.longitud() << endl;
    l.agregarNodo(7);
    l.insertarUltimo(25);
    l.mostrar();
    cout << "Longitud de la lista: " << l.longitud() << endl;
    l.remover();
    l.mostrar();
    l.remover();
    l.mostrar();
    l.mostrarRecursivo();
    cout << "Longitud de la lista: " << l.longitud() << endl;
    return 0;
}
