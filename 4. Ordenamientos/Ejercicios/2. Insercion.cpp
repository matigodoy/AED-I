#include <iostream>
#include <sstream>

using namespace std;

void insercion(int* a, int n){
    for (int i = 1; i < n; i++){
        int p = i;
        while(p > 0 && a[p-1] < a[p]){
            swap(a[p-1], a[p]);
            p--;    
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
    insercion(a, n);
    mostrar(a,n);

    return 0;
}
