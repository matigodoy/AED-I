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
        bool esAbb(nodo*);
        void mostrar(nodo*);
    public:
        Abb();
        void insertar(int);
        bool esAbb();
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

bool Abb::esAbb(){
    esAbb(raiz);
}

bool Abb::esAbb(nodo* hoja){
    if(hoja->derecho == NULL || hoja->izquierdo == NULL){
        return true;
    }
    if(hoja->dato < hoja->derecho->dato && hoja->dato > hoja->izquierdo->dato){
        esAbb(hoja->izquierdo);
        esAbb(hoja->derecho);
        return true;
    }
    else{
        return false;
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

    abb1.mostrar();

    if(abb1.esAbb() == true) cout<<"Es ABB "<<endl;
    else cout<<"No es ABB "<<endl;

    return 0;
}