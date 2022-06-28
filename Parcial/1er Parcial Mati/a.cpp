#include <iostream>
#include <sstream>

using namespace std;

int estaOrdenada(int* a, int n){
    int cont1=0,cont2=0;
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]<a[i+1]){
            cont1++;
        }
        if(a[i]>a[i+1]){
            cont2++;
        }
    }
    if(cont1 == n-1){
        return 1;
    }

    if(cont2 == n-1){
        return -1;
    }
    
    if(cont1 != n-1 || cont2 != n-1){
        return 0;
        
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
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    mostrar(a, n);
    int resultado=estaOrdenada(a,n);
    if(resultado == -1) cout<<"Esta ordenado de manera decreciente."<<endl;
    if(resultado == 1) cout<<"Esta ordenado de manera creciente."<<endl;
    if(resultado == 0) cout<<"Esta desordenado."<<endl;
    return 0;
}
