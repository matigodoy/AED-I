#include<iostream>
using namespace std;

struct nodo{
    int dato;
    nodo* izquierdo;
    nodo* derecho;
};

nodo* crearNodo(int dato){
    nodo* n = new nodo;
    n->dato=dato;
    n->izquierdo=NULL;
    n->derecho=NULL;
    return n;
}

int main(){

    nodo* arbol = NULL;
    arbol = crearNodo(1);
    arbol->izquierdo = crearNodo(2);
    arbol->derecho = crearNodo(3);
    arbol->izquierdo->izquierdo = crearNodo(4);
    arbol->izquierdo->derecho = crearNodo(5);

    delete arbol->izquierdo->derecho;
    delete arbol->izquierdo->izquierdo;
    delete arbol->derecho;
    delete arbol->izquierdo;
    delete arbol;

    return 0;
}