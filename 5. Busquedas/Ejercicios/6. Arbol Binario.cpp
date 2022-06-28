#include<iostream>
#include<queue>
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
    public:
        Abb();
        void insertar(int);
        void recorrerAmplitud();
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

void Abb::recorrerAmplitud(){
    cout<<"Recorrido en amplitud: "<<endl;
    queue <nodo*> c;
    nodo* n = raiz;
    while(n != NULL){
        cout << n->dato << "-";
        if(n->izquierdo != NULL) c.push(n->izquierdo);
        if(n->derecho != NULL) c.push(n->derecho);
        n = c.front();
        c.pop();
    }
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

    abb1.recorrerAmplitud();

    return 0;
}