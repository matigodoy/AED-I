#include<iostream>
#include<stdlib.h>
using namespace std;

class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona(string,int);
		virtual void mostrar();
};

class Alumno:public Persona{
	private:
		float notaFinal;
	public:
		Alumno(string,int,float);
		void mostrar();
};

class Profesor:public Persona{
	private:
		string materia;
	public:
		Profesor(string,int,string);
		void mostrar();
};

Persona::Persona(string nombre,int edad){
	this->nombre=nombre;
	this->edad=edad;
}

void Persona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

Alumno::Alumno(string nombre,int edad,float notaFinal):Persona(nombre,edad){
	this->notaFinal=notaFinal;
}

void Alumno::mostrar(){
	Persona::mostrar();
	cout<<"Nota Final: "<<notaFinal<<endl;
}

Profesor::Profesor(string nombre, int edad, string materia):Persona(nombre,edad){
	this->materia=materia;
}

void Profesor::mostrar(){
	Persona::mostrar();
	cout<<"Materia: "<<materia<<endl;
}

int main(){
	Persona *vector[3];
	
	vector[0] = new Alumno("Alegandro",20,18.9);
	vector[1] = new Alumno("Juan",19,15.5);
	vector[2] = new Profesor("Jose",25,"Programacion");
	
	vector[0]->mostrar();
	cout<<"\n";
	vector[1]->mostrar();
	cout<<"\n";
	vector[2]->mostrar();
	
	return 0;
}
