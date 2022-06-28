#include <iostream>
#include <sstream>

using namespace std;

int estaOrdenada(int* a, int n){
    n = n-1;
    int c1=0;
    int c2=0;
    for (int i = 0; i < n; i++){
        if(a[i]<a[i+1]){
            c1++;
        }
        if(a[i]>a[i+1]){
            c2++;
        }
    }
    if(c1 == n){
        return 1;
    }
    else if(c2 == n){
        return -1;
    }
    else{
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
    int a[] = {1,3,5,6,7,9}; //creciente
    //int a[] = {9,7,4,2,1}; //decreciente
    //int a[] = {5,8,2,4,9,1,2}; //desordenado
    //int a[] = {1};
    int n = sizeof(a)/sizeof(a[0]);

    mostrar(a, n);

    int resultado=estaOrdenada(a,n);

    if(resultado == 1) cout<<"Ordenado crecientemente "<<endl;
    if(resultado == -1)cout<<"Ordenado decrecientemente"<<endl;
    if(resultado == 0) cout<<"Desordenado"<<endl;
    return 0;
}