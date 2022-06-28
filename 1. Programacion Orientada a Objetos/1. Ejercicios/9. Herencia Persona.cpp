#include<iostream>
#include<stdlib.h>
using namespace std;

class Persona{
	private:
		string nombre;
		string apellido;
		int edad;
	public:
		Persona(string,string,int);
		virtual void mostrar();
};

class Alumno:public Persona{
	private:
		int legajo;
		int calificaciones[5];
	public:
		Alumno(string,string,int,int);
		void agregarCalificaciones();
		void mostrar();
};

class Profesor:public Persona{
	private:
		string materia;
		string legajo;
	public:
		Profesor(string,string,int,string,string);
		void mostrar();
};

Persona::Persona(string nombre,string apellido,int edad):nombre(nombre),apellido(apellido),edad(edad){}

void Persona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Apellido: "<<apellido<<endl;
	cout<<"Edad: "<<edad<<endl;
}

Alumno::Alumno(string nombre,string apellido,int edad,int legajo):Persona(nombre,apellido,edad),legajo(legajo){}

void Alumno::agregarCalificaciones(){
	for(int i=0;i<5;i++){
		calificaciones[i]=7;
	}
}

void Alumno::mostrar(){
	Persona::mostrar();
	cout<<"Legajo: "<<legajo<<endl;
	cout<<"Calificaciones"<<endl;
	for(int i=0;i<5;i++){
		cout<<"  *Calificacion: "<<calificaciones[i]<<endl;
	}
}

Profesor::Profesor(string nombre,string apellido, int edad, string materia, string legajo):Persona(nombre,apellido,edad),materia(materia),legajo(legajo){}

void Profesor::mostrar(){
	Persona::mostrar();
	cout<<"Materia: "<<materia<<endl;
	cout<<"Legajo: "<<legajo<<endl;
}

int main(){
	Persona *p;
	Alumno alumno1("Federico","Marquez",18,4562);
	p=&alumno1;
	alumno1.agregarCalificaciones();
	cout<<"    -Alumno-"<<endl;
	p->mostrar();
	
	Profesor profesor1("Jose","Russo",56,"Matematica","1753F5");
	p=&profesor1;
	cout<<"\n    -Profesor-"<<endl;
	p->mostrar();
	
	return 0;
}
