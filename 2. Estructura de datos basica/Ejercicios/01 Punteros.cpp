#include<iostream>
#include <iostream>
using namespace std;

void cambiar(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main(){
    int n1,n2;
    cout<<"Ingrese el valor de n1: "<<endl;
    cin>>n1;
    cout<<"Ingrese el valor de n2: "<<endl;
    cin>>n2;
    cout<<"Antes de intercambiar"<<endl;
    cout<<"n1 = "<<n1<<" y n2 = "<<n2<<endl;

    cambiar(&n1,&n2);

    cout<<"Despues de intercambiar"<<endl;
    cout<<"n1 = "<<n1<<" y n2 = "<<n2<<endl;
    return 0;
}