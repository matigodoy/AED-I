#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct nodo{
	int dato;
	nodo* siguiente;
};

class Alumno{
	private:
		int legajo;
		string nombre;
		string apellido;
		nodo* inicio;
	public:
		Alumno(int,string,string);
		string getNombre();
		string getApellido();
		int getLegajo();
		void setNombre(string);
		void setApellido(string);
		void agregarCalificaciones();
		void mostrarCalificaciones();
		double getPromedio();
		string toString();
};
Alumno::Alumno(int legajo, string nombre, string apellido):legajo(legajo),nombre(nombre),apellido(apellido){
	inicio=NULL;
}

string Alumno::getNombre(){
	return nombre;
}
string Alumno::getApellido(){
	return apellido;
}
int Alumno::getLegajo(){
	return legajo;
}
void Alumno::setNombre(string nombre){
	this->nombre=nombre;
}
void Alumno::setApellido(string apellido){
	this->apellido=apellido;
}
void Alumno::agregarCalificaciones(){
	for(int i=0;i<10;i++){
		nodo* n = new nodo();
		n->dato = 1+rand()%(11-1);
		n->siguiente = inicio;
		inicio = n;
	}
}
void Alumno::mostrarCalificaciones(){
	nodo* n = inicio;
	while(n != NULL){
		cout<<"Nota: "<<n->dato<<endl;
		n = n->siguiente;
	}
}
double Alumno::getPromedio(){
	nodo* n = inicio;
	int total=0;
	while(n != NULL){
		total = total + n->dato;
		n = n->siguiente;
	}
	return total/10;
}

string Alumno::toString(){
    stringstream s;
	s<<"DATOS DEL ALUMNO: "<<endl;
    s<<"Nombre: "<<this->getNombre()<<endl;
	s<<"Apellido: "<<this->getApellido()<<endl;
	s<<"Legajo: "<<this->getLegajo()<<endl;
    return s.str();
}

int main(){
	Alumno a1(12345,"Federico","Marquez");

	cout<<a1.toString()<<endl;

	cout<<"AGREGAR CALIFICACIONES "<<endl;
	a1.agregarCalificaciones();
	a1.mostrarCalificaciones();

	cout<<"\nMOSTRAR PROMEDIO: "<<a1.getPromedio();
	
	return 0;
}
