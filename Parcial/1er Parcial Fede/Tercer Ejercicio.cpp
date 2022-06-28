#include <iostream>
using namespace std;

void mostrar(int* a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;    
}

void determinar(int* a, int* b, int n){
    int fin=n;
    int comienzo=0;
    for (int i = 0; i < n; i++){
        if(a[i]>0){
            b[fin]=a[i];
            fin--;
        }
        if(a[i]<0){
            b[comienzo]=a[i];
            comienzo++;
        }
    }
    for (int i = 0; i < n; i++){
        a[i] = b[i];
    }
}

int main(){
    int a[] = {4,-3,7,9-12,-8,5,-14};
    int n = sizeof(a)/sizeof(a[0]);
    int b[n];
    for (int i = 0; i < n; i++){ b[i] = 0;}
   
    mostrar(a, n);
    determinar(a,b,n);
    mostrar(a,n);

    return 0;
}