#include <iostream>
#include <sstream>

using namespace std;

void vector2(int* v2, int* v, int n){
    for (int i = 0; i < 6; i++){
        v2[i]=0;
    }
    
    for (int i = 0; i < n; i++){
        v2[((v[i])-1)]++;
    }
}

void frecuencia(int* v2, int* v3, int n){
    int mayor=0;
    int k=0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if(mayor<v2[j] || mayor==v2[j]){
                if(v2[j] != 0){
                    mayor=j+1;
                }
                k=j;
            }
        }
        v2[k]=0;
        v3[i]=mayor;
        mayor=0;
        k=0;
    }
}

void mostrar(int* v, int* v3, int n){
    cout<<"Input"<<endl;
    for (int i = 0; i < n; i++){
        if(v[i] != 0){
            cout<<" | "<<v[i];
        }
    }
    cout<<" |"<<endl;

    cout<<"Ouput"<<endl;
    for (int i = 0; i < 6; i++){
        if(v3[i] != 0){
            cout<<" | "<<v3[i];
        }
    }
    cout<<" |"<<endl;
}

int main(){
    int v[] = {4,4,5,5,6,5,1,6,4,4};
    int n = sizeof(v)/sizeof(v[0]);
    int v2[6];
    int v3[6];

    vector2(v2,v,n);
    
    frecuencia(v2,v3,n);

    mostrar(v,v3,n);

    return 0;
}