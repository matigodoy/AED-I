#include<iostream>
using namespace std;
int main(){
	int N=10;
	int valores[N];
	for(int i=0; i<N; i++){
		cout<<"Ingrese valor ["<<i+1<<"]: ";
		cin>>valores[i];
	}
	for(int i=0; i<10; i++){
		for(int j=i+1; j<10; j++){
			if(valores[i]==valores[j]){
				cout<<"El valor "<<valores[i]<<" esta repetido en las posiciones "<<i+1<<" y "<<j+1<<endl;
			}
		}
	}
}
