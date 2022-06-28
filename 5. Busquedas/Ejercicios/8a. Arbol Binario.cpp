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
        nodo* obtenerMenor(nodo*);
        nodo* obtenerMayor(nodo*);
    public:
        Abb();
        void insertar(int);
        nodo* obtenerMenor();
        nodo* obtenerMayor();
};

Abb::Abb(){
    raiz = NULL;
}

nodo* Abb::obtenerMenor(nodo* hoja){
    if(hoja == NULL){
        return NULL;
    }
    else if(hoja->izquierdo == NULL){
        return hoja;
    }
    else{
        return obtenerMenor(hoja->izquierdo);
    }
}

nodo* Abb::obtenerMenor(){
    return obtenerMenor(raiz);
}

nodo* Abb::obtenerMayor(nodo* hoja){
    if(hoja == NULL){
        return NULL;
    }
    else if(hoja->derecho == NULL){
        return hoja;
    }
    else{
        return obtenerMayor(hoja->derecho);
    }
}

nodo* Abb::obtenerMayor(){
    return obtenerMayor(raiz);
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

    cout<<"Buscando menor: "<<abb1.obtenerMenor()->dato<<endl;

    cout<<"Buscando mayor: "<<abb1.obtenerMayor()->dato<<endl;

    return 0;
}