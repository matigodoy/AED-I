#include <iostream>
using namespace std;

int main(){
	int arr[10]; //se declara un vector
	int* pa; //se declara un puntero
	
	pa=&arr[0]; //se le asigna al puntero la direccion de memoria del primer elemento del vector
	
	//pide al usuario los elementos del vector
	cout<<"Ingrese los elementos del array:\n"<<endl;
	for(int i=0;i < 10; i++){
		cout<<"Ingrese a["<<i+1<<"]: ";
		cin>> *(pa+i); //como estamos utilizando punteros y los elementos del vector son correlativos en la memoria, solo hace falta ir sumandole +1 al puntero ya que apunta a una direccion de memoria y el siguiente elemento del vector va a estar correlativo al anterior. 
	}
	
	//muestra el vector
	cout<<endl<<"Los elementos del array son:\n"<<endl;
	for(int i=0;i<10;i++){
		cout<<pa+i<<"\t\t"<<*(pa+i)<<endl; //aca muestra la direccion de memoria donde se encuentra cada elemento del vector y a la derecha muestra el elemento del vector con la misma logica que cuando se ingresaron los elementos.
	}
	
	return 0;
}
