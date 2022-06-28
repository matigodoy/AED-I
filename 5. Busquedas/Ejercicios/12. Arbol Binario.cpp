#include <iostream>
#include <sstream>

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
        nodo* insertar(int, nodo*);
        nodo* eliminarNodo(nodo*, int);
        nodo* buscarMenor(nodo* hoja);
        void mostrar(nodo*);
    public:
        Abb();
        void insertar(int);
        void eliminarNodo(int);
        void mostrar();
};

nodo* Abb::buscarMenor(nodo* hoja){
    if (hoja == NULL){
        return NULL;
    }
    else if (hoja->izquierdo == NULL){
        return hoja;        
    }
    else{
        return buscarMenor(hoja->izquierdo);
    }

}

nodo* Abb::crearNodo(int dato){
    nodo* n = new nodo;
    n->dato = dato;
    n->izquierdo = NULL;
    n->derecho = NULL;
    return n;
}

nodo* Abb::insertar(int dato, nodo* hoja){
    if (hoja == NULL){
        // Insertar el nuevo elemento
        hoja = crearNodo(dato);
    }
    else if (dato < hoja->dato){
        hoja->izquierdo = insertar(dato, hoja->izquierdo);
    }
    else {
        hoja->derecho = insertar(dato, hoja->derecho);
    } 
    return hoja;
}

void Abb::insertar(int dato){
    raiz = insertar(dato, raiz);
}

Abb::Abb(){
    raiz = NULL;
}

nodo* Abb::eliminarNodo(nodo* hoja, int dato){
    if (hoja){
        if (dato < hoja->dato) hoja->izquierdo = eliminarNodo(hoja->izquierdo, dato);
        else if (dato > hoja->dato) hoja->derecho = eliminarNodo(hoja->derecho, dato);
        else { // lo encontré --> lo elimino
            // Caso 1: es una hoja
            if (hoja->izquierdo == NULL && hoja->derecho == NULL){
                delete hoja;
                hoja = NULL;
            }            
            // Caso 2: tiene un solo hijo
            else if(hoja->izquierdo == NULL){
                nodo* aux = hoja;
                hoja = hoja->derecho;
                delete aux;
            }
            else if(hoja->derecho == NULL){
                nodo* aux = hoja;
                hoja = hoja->izquierdo;
                delete aux;
            }
            // Caso 3: tiene dos hijos
            else{
                nodo* aux = buscarMenor(hoja->derecho);
                hoja->dato = aux->dato;
                eliminarNodo(hoja->derecho, aux->dato);
            }
        }
    }
    return hoja;
}

void Abb::eliminarNodo(int dato){
    raiz  = eliminarNodo(raiz, dato);
}

void Abb::mostrar(){
    cout<<"Mostrar: "<<endl;
    mostrar(raiz);
    cout<<"Fin"<<endl;
}

void Abb::mostrar(nodo* hoja){
    if(hoja != NULL){
        cout<<hoja->dato<<" -- ";
        mostrar(hoja->izquierdo);
        mostrar(hoja->derecho);
    }
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
    abb1.insertar(2);

    abb1.eliminarNodo(1);

    abb1.mostrar();

    return 0;
}