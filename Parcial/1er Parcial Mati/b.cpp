#include <iostream>
#include <sstream>

using namespace std;

void ordenar(int* v1, int* v2, int n){
    int ultimo=n;
    int principio=0;
    for (int i = 0; i < n; i++)
    {   
        if(v1[i]>0){
            v2[ultimo]=v1[i];
            ultimo--;
        }
        if(v1[i]<0){
            v2[principio]=v1[i];
            principio++;
        }
    }
}

void mostrar(int* v1, int n){
    for (int i = 0; i < n; i++)
    {
        cout << v1[i] << "\t";
    }
    cout << endl;    
}

int main(){
    int v1[] = {-1, 2, 6, 15, 21, 12, 3, -3, -7, 5, 7, 16};
    int n = sizeof(v1)/sizeof(v1[0]);
    int v2[n];
    
    for (int i = 0; i < n; i++)
    { 
        v2[i] = 0;
    }
   
    mostrar(v1, n);
    ordenar(v1,v2,n);
    mostrar(v2,n);

    return 0;
}