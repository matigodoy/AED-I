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
        nodo* buscar(int, nodo*);
        void mostrar(nodo*);
    public:
        Abb();
        void insertar(int);
        nodo* buscar(int);
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

nodo* Abb::buscar(int dato){
    return buscar(dato,raiz);
}

nodo* Abb::buscar(int dato, nodo* hoja){
    if(hoja == NULL){
        return NULL;
    }
    if (dato == hoja ->dato){
        return hoja;
    }
    else if(dato < hoja->dato){
        return buscar(dato, hoja->izquierdo);
    }
    else{
        return buscar(dato, hoja->derecho);
    }
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

    abb1.mostrar();

    cout<<"El valor 6 "<< (abb1.buscar(6) ? "si":"no") << " esta. "<<endl; 
    cout<<"El valor 15 "<< (abb1.buscar(15) ? "si":"no") << " esta. "<<endl;

    return 0;
}