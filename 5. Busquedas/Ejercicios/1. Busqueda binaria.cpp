#include<iostream>
using namespace std;

int busquedaBinariaRecursiva(int x, int* a, int inicio, int fin){
    if(inicio <= fin){
        int medio = inicio + ((fin - inicio) / 2);
        if (x == a[medio]) return medio;
        else if(x < a[medio]) return busquedaBinariaRecursiva(x,a,inicio,medio-1);
        else return busquedaBinariaRecursiva(x,a,medio+1,fin);
    }
    return -1;
}

int busquedaBinaria(int x, int* a, int n){
    int inicio = 0;
    int fin = n-1;

    while(inicio <= fin){
        int medio = inicio + ((fin - inicio) / 2);
        if (x== a[medio]){
            return medio;
        }
        else if(x<a[medio]){
            fin = medio - 1;
        }
        else{
            inicio = medio + 1;
        }
    }
    return -1;
}

int main(){
    int a[] = {2,3,5,9,12,16,21,22,23,25,27,29,31};
    int n = sizeof(a)/sizeof(a[0]);

    int x=250;

    //int posicionX = busquedaBinaria(x,a,n);

    int posicionX = busquedaBinariaRecursiva(x,a,0,n-1)+1;

    if (posicionX == 0){
        cout<<"No se encontro el valor: "<<x<<endl;
    }
    else{
        cout<<"El valor "<<x<<" esta en la posicion "<<posicionX<<endl;
    }

    return 0;
}