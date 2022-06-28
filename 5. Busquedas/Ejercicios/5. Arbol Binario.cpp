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
        void inOrden(nodo*);
        void preOrden(nodo*);
        void postOrden(nodo*);
    public:
        Abb();
        void insertar(int);
        void inOrden();
        void preOrden();
        void postOrden();
};

Abb::Abb(){
    raiz = NULL;
}

void Abb::preOrden(nodo* hoja){
    if(hoja != NULL){
        cout<<hoja->dato<<" -- ";
        preOrden(hoja->izquierdo);
        preOrden(hoja->derecho);
    }
}

void Abb::preOrden(){
    cout<<"Recorrido preorden"<<endl;
    preOrden(raiz);
    cout<<"Fin"<<endl;
}

void Abb::inOrden(nodo* hoja){
    if(hoja != NULL){
        inOrden(hoja->izquierdo);
        cout<< hoja->dato << " -- ";
        inOrden(hoja->derecho);
    }
}

void Abb::inOrden(){
    cout<<"Recorrido inorden"<<endl;
    inOrden(raiz);
    cout<<"Fin"<<endl;
}

void Abb::postOrden(nodo* hoja){
    if(hoja != NULL){
        postOrden(hoja->izquierdo);
        postOrden(hoja->derecho);
        cout<<hoja->dato<<" -- ";
    }
}

void Abb::postOrden(){
    cout<<"Recorrido postorden: "<<endl;
    postOrden(raiz);
    cout<<"Fin "<<endl;
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

    abb1.insertar(73);
    abb1.insertar(71);
    abb1.insertar(67);
    abb1.insertar(75);
    abb1.insertar(68);
    abb1.insertar(79);
    abb1.insertar(69);
    abb1.insertar(78);
    abb1.insertar(70);
    abb1.insertar(72);
    abb1.insertar(77);
    abb1.insertar(76);
    abb1.insertar(74);

    abb1.inOrden();

    abb1.preOrden();

    abb1.postOrden();

    return 0;
}
