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
        int niveles(int, nodo*,int*);
        void mostrarNivel2(nodo*);
        void mostrar(nodo*);
    public:
        Abb();
        void insertar(int);
        void mostrarNivel2();
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

int Abb::niveles(int dato, nodo* hoja, int* contador){
    if(hoja == NULL){
        return -1;
    }
    if (dato == hoja ->dato){
        return *contador;
    }
    else if(dato < hoja->dato){
        *contador = *contador + 1;
        niveles(dato, hoja->izquierdo, contador);
        return *contador;
    }
    else{
        *contador = *contador + 1;
        niveles(dato, hoja->derecho, contador);
        return *contador;
    }
}

void Abb::mostrarNivel2(nodo* hoja){
    int contador = 0;
    if(hoja != NULL){
        mostrarNivel2(hoja->izquierdo);
        mostrarNivel2(hoja->derecho);
        if((niveles(hoja->dato,raiz, &contador)) >= 2){
            cout<<hoja->dato<<" -- ";
        }
    }
}

void Abb::mostrarNivel2(){
    cout<<"Nodo desde el nivel 2:  ";
    mostrarNivel2(raiz);
    cout<<"Fin "<<endl;
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

    abb1.mostrarNivel2();

    return 0;
}
