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
        bool esAbbInorden(nodo*);
        void mostrar(nodo*);
    public:
        Abb();
        void insertar(int);
        bool esAbbInorden();
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

void Abb::mostrar(nodo* hoja){
    if(hoja != NULL){
        cout<<hoja->dato<<" -- ";
        mostrar(hoja->izquierdo);
        mostrar(hoja->derecho);
    }
}
bool Abb::esAbbInorden(){
    esAbbInorden(raiz);
}

bool Abb::esAbbInorden(nodo* hoja){
    if(hoja->izquierdo == NULL || hoja->derecho == NULL){
        return true;
    }
    else{
        esAbbInorden(hoja->izquierdo);
        if(hoja->dato > hoja->izquierdo->dato){
            esAbbInorden(hoja->derecho);
            if(hoja->dato < hoja->derecho->dato){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
}

void Abb::mostrar(){
    cout<<"Mostrar: "<<endl;
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

    if(abb1.esAbbInorden() == true) cout<<"Es Abb "<<endl;
    else cout<<"No es Abb "<<endl;

    return 0;
}