#include<iostream>
#define N 50
#define TAM_ALFABETO 26
using namespace std;
int main(){
	char cadena[N];
	int contadores [TAM_ALFABETO];
	for (int i=0;i <TAM_ALFABETO;i++)
		contadores[i]=0;
		cout<<"Ingrese una cadena en minusculas:"<<endl;
		cin.getline(cadena,N);
		
	for(int i=0; i<N; i++){
		if(cadena[i]>=97 && cadena[i] <= 122)
			contadores[cadena[i]-97]++;
	}
	cout<<"La cadena tiene: "<<endl;
	for(int i=0; i<TAM_ALFABETO; i++){
		if(contadores[i])
			cout<<contadores[i]<<" "<<(char)(i+97)<<endl;
	}
}
