#include <iostream>
#include <sstream>

using namespace std;

void burbuja(int* a, int n){
    bool ordenado = false;
    while(!ordenado){
        ordenado = true;
        for (int i = 0; i < n-1; i++)
        {
            if (a[i+1] < a[i]){
                swap(a[i+1], a[i]);
                ordenado = false;
            }         
        }
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
    burbuja(a, n);
    mostrar(a,n);
    
    return 0;
}