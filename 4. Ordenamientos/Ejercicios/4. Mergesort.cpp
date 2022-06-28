#include <iostream>
#include <sstream>

using namespace std;

void merge(int* izq, int* der, int* a, int nIzq, int nDer, int n){
    int i = 0, j = 0, k = 0;

    while (i < nIzq && j < nDer){
        if (izq[i] < der[j]) {
            a[k] = izq[i];
            k++; 
            i++;
        }
        else
        {
            a[k] = der[j];
            k++;
            j++;
        }
    }

    while(i < nIzq) {
        a[k] = izq[i];
        k++; 
        i++;
    }

    while(j < nDer){
        a[k] = der[j];
        k++;
        j++;
    }
}

void mergesort(int * a, int n){
    if (n < 2) return;
    int mitad = n/2;

    // Creamos los arreglos izquierdo y derecho
    int* izq = new int[mitad];
    int* der = new int[n-mitad];

    // Trasvasamos el array a a izq y der
    for (int i = 0; i < mitad; i++){izq[i] = a[i];}
    for (int i = mitad; i < n; i++){der[i-mitad] = a[i];}
    
    mergesort(izq, mitad);
    mergesort(der, n-mitad);

    merge(izq, der, a, mitad, n-mitad, n);

    delete[] izq;
    delete[] der;
}

void mostrar(int* a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;    
}

int main(){
    int a[] = {5, 10, 2, 6, 15, 21, 12, 3, 7, 16};
    int n = sizeof(a)/sizeof(a[0]);

    mostrar(a, n);
    mergesort(a, n);
    mostrar(a,n);

    return 0;
}
