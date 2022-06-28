#include <iostream>
#include <stack>
 
using namespace std;
 
void burbuja(int* v, int n){
    bool ordenado = false;
    while(!ordenado){
        ordenado = true;
        for (int i = 0; i < n-1; i++)
        {
            if (v[i+1] < v[i]){
                swap(v[i+1], v[i]);
                ordenado = false;
            }         
        }
    }
}
 
void mostrar(int* v, int n, int* posicion){
    cout<<"Vector Ordenado "<<endl;
    for (int i = 0; i < n; i++){
        cout << v[i] << "\t";
    }
    cout << endl;
    cout<<"Valores con la menor distancia: "<<v[*posicion]<<" | "<<v[*posicion+1]<<endl;
}
 
void par(int* v,int n, int* posicion){
    int distancia=(v[1]-v[0])+1;//999999
    for (int i = 0; i<n-1; i++){
        if(distancia>v[i+1]-v[i]){
            distancia=v[i+1]-v[i];
            *posicion=i;
        }
    }
}
 
int main(){
    int v[] = {5,9,8,25,42,84};
    int n = sizeof(v)/sizeof(v[0]);
    int posicion=0;
 
    burbuja(v, n);
    par(v,n,&posicion);
    mostrar(v,n,&posicion);
}
