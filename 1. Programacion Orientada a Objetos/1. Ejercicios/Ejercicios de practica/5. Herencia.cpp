#include<iostream>
#include<stdlib.h>
using namespace std;

class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona(string,int);
		void mostrarPersona();
};

class Empleado:public Persona{
	private:
		float sueldo;
	public:
		Empleado(string,int,float);
		void mostrarEmpleado();
};

class Estudiante:public Persona{
	private:
		float notaFinal;
	public:
		Estudiante(string,int,float);
		void mostrarEstudiante();
};

class Universitario:public Estudiante{
	private:
		string carrera;
	public:
		Universitario(string,int,float,string);
		void mostrarUniversitario();
};

Persona::Persona(string nombre,int edad){
	this->nombre=nombre;
	this->edad=edad;
}

void Persona::mostrarPersona(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

Empleado::Empleado(string nombre,int edad,float sueldo):Persona(nombre,edad){
	this->sueldo=sueldo;
}

void Empleado::mostrarEmpleado(){
	mostrarPersona();
	cout<<"Sueldo: "<<sueldo<<endl;
}

Estudiante::Estudiante(string nombre,int edad,float notaFinal):Persona(nombre,edad){
	this->notaFinal=notaFinal;
}

void Estudiante::mostrarEstudiante(){
	mostrarPersona();
	cout<<"Nota Final: "<<notaFinal<<endl;
}

Universitario::Universitario(string nombre,int edad,float notaFinal,string carrera):Estudiante(nombre,edad,notaFinal){
	this->carrera=carrera;
}

void Universitario::mostrarUniversitario(){
	mostrarEstudiante();
	cout<<"Carrera: "<<carrera<<endl;
}

int main(){
	Empleado emp1("Juan",20,1400);
	cout<<"-Empleado-"<<endl;
	emp1.mostrarEmpleado();
	cout<<"\n";
	
	Estudiante est1("Federico",14,14.7);
	cout<<"-Estudiante-"<<endl;
	est1.mostrarEstudiante();
	cout<<"\n";
	
	Universitario univ1("Francisco",18,15.6,"Informatica");
	cout<<"Universitario-"<<endl;
	univ1.mostrarUniversitario();
	cout<<"\n";
}
