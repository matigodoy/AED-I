#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Alumno{
	private:
		int legajo;
		string nombre;
		string apellido;
		int calificaciones[10];
		int cant;
	public:
		Alumno(int,string,string,int);
		string getNombre();
		string getApellido();
		int getLegajo();
		void setNombre(string);
		void setApellido(string);
		void agregarCalificaciones();
		double getPromedio();
		string toString();
};
Alumno::Alumno(int legajo, string nombre, string apellido,int cant):legajo(legajo),nombre(nombre),apellido(apellido),cant(cant){}

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
	int n=0;
	do{
		cout<<"Ingrese la cantidad de calificaciones que va a cargar: ";
		cin>>n;
		if(n>10 || n<1)cout<<"Se pueden ingresar como maximo 10 calificaciones "<<endl;
	}while(n>10 || n<1);
	cant=n;
	for(int i=0;i<n;i++){
		do{
			cout<<"Ingrese la calificacion numero "<<i+1<<" : ";
			cin>>calificaciones[i];
			if(calificaciones[i]<1 || calificaciones[i]>10)cout<<"Las calificaciones son del '1' al '10' "<<endl;
		}while(calificaciones[i]<1 || calificaciones[i]>10);
		this->calificaciones[i]=calificaciones[i];
	}
}
double Alumno::getPromedio(){
	if(cant==0){
		cout<<"No se ingresaron calificaciones. "<<endl;
		return 0;
	}
	else{
		double a=0;
		for(int i=0;i<cant;i++){
			a=calificaciones[i]+a;
		}
		return a/cant;
	}
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
	int _legajo;
	string _apellido, _nombre;
	cout<<"Ingrese su nombre: ";
	getline(cin,_nombre);
	cout<<"Ingrese su apellido: ";
	getline(cin,_apellido);
	do{
		cout<<"Ingrese su legajo: ";
		cin>>_legajo;
    	if(_legajo<0)cout<<"El legajo tiene que ser un numero positivo "<<endl;
    }while(_legajo<0);
	Alumno a1(_legajo,_nombre,_apellido,0);

	cout<<a1.toString()<<endl;

	cout<<"CAMBIAR NOMBRE Y APELLIDO. "<<endl;
	cout<<"Ingrese su nombre: ";
	getline(cin,_nombre);
	a1.setNombre(_nombre);
	cout<<"Ingrese su apellido: ";
	getline(cin,_apellido);
	a1.setApellido(_apellido);
	cout<<"Nombre y Apellido cambiado con exito "<<endl;

	cout<<"AGREGAR CALIFICACIONES "<<endl;
	a1.agregarCalificaciones();

	cout<<"MOSTRAR PROMEDIO: "<<a1.getPromedio();
	
	return 0;
}
