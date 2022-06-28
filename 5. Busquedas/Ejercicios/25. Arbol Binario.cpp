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
        void mostrar(nodo*);
        int distancia(nodo*,int,int);
        void calculardistancia(nodo*, int, int*);
    public:
        Abb();
        void insertar(int);
        void mostrar();
        int distancia(int,int);
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

void Abb::mostrar(){
    cout<<"Mostrar: ";
    mostrar(raiz);
    cout<<"Fin"<<endl;
}

int Abb::distancia(int a,int b){
    return distancia(raiz,a,b);
}

int Abb::distancia(nodo* hoja,int a,int b){
    if(hoja->dato > a && hoja->dato > b) distancia(hoja->izquierdo,a,b);
    else if(hoja->dato < a && hoja->dato < b) distancia(hoja->derecho,a,b);
    else{
        int contador1=0,contador2=0;
        calculardistancia(hoja,a,&contador1);
        calculardistancia(hoja,b,&contador2);
        return contador1+contador2;
    }
}

void Abb::calculardistancia(nodo* hoja, int a, int* contador){
    if (a == hoja ->dato){
        return;
    }
    else if(a < hoja->dato){
        *contador = *contador +1;
        calculardistancia(hoja->izquierdo,a,contador);
    }
    else{
        *contador = *contador +1;
        calculardistancia(hoja->derecho,a,contador);
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

    abb1.mostrar();

    cout<<"La distancia entre los dos numeros es: "<<abb1.distancia(9,15)<<endl; //se rompe cuando agregas valores que no existen, se soluciona llamando una funcion previamente para hacer la corroboracion

    return 0;
}