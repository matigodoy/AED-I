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
        bool Balanceado(nodo*);
        int altura(nodo*);
        int max(int, int);
    public:
        Abb();
        void insertar(int);
        void mostrar();
        bool Balanceado();
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

bool Abb::Balanceado(){
    return Balanceado(raiz);
}

bool Abb::Balanceado(nodo* hoja){ 
    if (hoja == NULL) return true;
    int lh = altura(hoja->izquierdo); 
    int rh = altura(hoja->derecho);
    if (abs(lh - rh) <= 1 && Balanceado(hoja->izquierdo) && Balanceado(hoja->derecho)) return true;
    return false;
}
 
int Abb::max(int a, int b){
    return (a >= b) ? a : b; 
}

int Abb::altura(nodo* node){ 
    if (node == NULL) 
    return 0;
    return 1 + max(altura(node->izquierdo), altura(node->derecho)); 
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

    abb1.insertar(6);
    abb1.insertar(3);
    abb1.insertar(8);
    abb1.insertar(1);
    //abb1.insertar(2);
    abb1.insertar(4);

    abb1.mostrar();

    if (abb1.Balanceado() == true) cout << "Esta balaneaco";
    else cout << "No esta balanceado"; 


    return 0;
}