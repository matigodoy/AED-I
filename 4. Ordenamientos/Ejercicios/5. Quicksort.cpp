#include <iostream>
#include <sstream>

using namespace std;

int particion(int* a, int principio, int fin){
    int pivot = a[fin];
    int p = principio;

    for (int i = principio; i <= fin; i++)
    {
        if(a[i] < pivot){
            swap(a[i], a[p]);
            p++;
        }
    }
    swap(a[p], a[fin]);
    return p;  
}

void quicksort(int* a, int principio, int fin){
    // solo si el sub arreglo es de longitud > 1
    if(principio < fin){
        int p = particion(a, principio, fin);
        quicksort(a, principio, p-1);
        quicksort(a, p+1, fin);
    }
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
    quicksort(a, 0, n-1);
    mostrar(a,n);

    return 0;
}