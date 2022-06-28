#include <iostream>
#include <sstream>

using namespace std;

void seleccion(int* a, int n){
    for (int i = 0; i < n; i++)
    {
        int iMenor = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[iMenor]){
                iMenor = j;
            }
        }
        swap(a[i], a[iMenor]);        
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
    seleccion(a, n);
    mostrar(a,n);
    
    return 0;
}