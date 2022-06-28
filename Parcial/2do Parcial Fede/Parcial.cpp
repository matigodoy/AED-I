#include<iostream>
using namespace std;

struct nodo{
    int dato;
    nodo* izquierdo;
    nodo* derecho;
};

class Abb{
    private:
        nodo* raiz;
        nodo* crearNodo(int);
        nodo* insertar(int,nodo*);
        void mostrarhojas(nodo*);
        void mostrar(nodo*);
    public:
        Abb();
        void insertar(int);
        void mostrarhojas();
        void mostrar();
};

Abb::Abb(){
    raiz = NULL;
}

nodo* Abb::insertar(int dato, nodo* hoja){
    if(hoja == NULL){
        hoja = crearNodo(dato);
    }
    else if(dato < hoja->dato){
        hoja->izquierdo=insertar(dato, hoja->izquierdo);
    }
    else{
        hoja->derecho=insertar(dato, hoja->derecho);
    }
    return hoja;
}

void Abb::insertar(int dato){
    raiz = insertar(dato, raiz);
}

nodo* Abb::crearNodo(int dato){
    nodo* n = new nodo;
    n->dato = dato;
    n->izquierdo = NULL;
    n->derecho = NULL;
    return n;
}

void Abb::mostrarhojas(){
    cout<<"Mostrar Hojas: ";
    mostrarhojas(raiz);
    cout<<"Fin hojas "<<endl;
    return;
}

void Abb::mostrarhojas(nodo* hoja){
    if(hoja != NULL){
        mostrarhojas(hoja->izquierdo);
        mostrarhojas(hoja->derecho);
        if(hoja->derecho == NULL && hoja->izquierdo == NULL){
            cout<<hoja->dato<<" -- ";
        }
    }
    return;
}

void Abb::mostrar(nodo* hoja){
    if(hoja != NULL){
        cout<<hoja->dato<<" -- ";
        mostrar(hoja->izquierdo);
        mostrar(hoja->derecho);
    }
}

void Abb::mostrar(){
    cout<<"Mostrar: ";
    mostrar(raiz);
    cout<<"Fin"<<endl;
}

int main(){
    Abb abb1;

    abb1.insertar(7);
    abb1.insertar(12);
    abb1.insertar(1);
    abb1.insertar(14);
    abb1.insertar(3);
    abb1.insertar(15);
    abb1.insertar(9);
    abb1.insertar(6);
    abb1.insertar(2);

    abb1.mostrar();

    abb1.mostrarhojas();

    return 0;
}