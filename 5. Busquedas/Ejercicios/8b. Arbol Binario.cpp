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
        int obtenerAltura(nodo*);
    public:
        Abb();
        void insertar(int);
        int obtenerAltura();
};

Abb::Abb(){
    raiz = NULL;
}

int Abb::obtenerAltura(nodo* hoja){
    if(hoja==NULL){
        return -1;
    }
    else{
        return max(obtenerAltura(hoja->izquierdo), obtenerAltura(hoja->derecho)) + 1;
    }
}

int Abb::obtenerAltura(){
    return obtenerAltura(raiz);
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

    cout<<"Altura: "<<abb1.obtenerAltura()<<endl;

    return 0;
}