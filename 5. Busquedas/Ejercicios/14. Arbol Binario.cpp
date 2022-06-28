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
        int obtenerSegundoMayor(nodo*, int*);
    public:
        Abb();
        void insertar(int);
        int obtenerSegundoMayor();
};
 
Abb::Abb(){
    raiz = NULL;
}
 
int Abb::obtenerSegundoMayor(nodo* hoja, int* anterior){
    if(hoja == NULL){
        return NULL;
    }
    else if(hoja->derecho == NULL){
        return *anterior;
    }
    else{
        *anterior = hoja->dato;
        return obtenerSegundoMayor(hoja->derecho, anterior);
    }
}
 
int Abb::obtenerSegundoMayor(){
    int anterior = 0;
    return obtenerSegundoMayor(raiz, &anterior);
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
 
    cout<<"El segundo mayor es: "<<abb1.obtenerSegundoMayor()<<endl;
 
    return 0;
}