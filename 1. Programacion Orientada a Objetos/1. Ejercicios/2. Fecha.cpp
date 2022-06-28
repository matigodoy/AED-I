#include<iostream>
#include<sstream>
using namespace std;

class Fecha{
	private:
		int dia,mes,anio;
	public:
		Fecha(int,int,int);
		int getDia(); //get muestra
		int getMes();
		int getAnio();
		void setDia(int); //set modifica
		void setMes(int);
		void setAnio(int);
		void agregarDias(int);
		void agregarMeses(int);
		void agregarAnios(int);
		string toString();
};
Fecha::Fecha(int dia,int mes, int anio):dia(dia),mes(mes),anio(anio){}

int Fecha::getDia(){
	return dia;
}
int Fecha::getMes(){
	return mes;
}
int Fecha::getAnio(){
	return anio;
}
void Fecha::setDia(int dia){
	this->dia=dia;
}
void Fecha::setMes(int mes){
	this->mes=mes;
}
void Fecha::setAnio(int anio){
	this->anio=anio;
}
void Fecha::agregarDias(int a){
	setDia(getDia()+a);
	if(getDia()>31){
		int b=0;
		b=getDia()/31;
		setDia(getDia()-b*31);
		setMes(getMes()+b);
		if(getMes()>12){
			int c=0;
			c=getMes()/12;
			setMes(getMes()-(c*12));
			setAnio(getAnio()+c);
		}
	}
}
void Fecha::agregarMeses(int a){
	setMes(getMes()+a);
	if(getMes()>12){
		int b=0;
		b=getMes()/12;
		setMes(getMes()-(b*12));
		setAnio(getAnio()+b);
	}
}
void Fecha::agregarAnios(int a){
	setAnio(getAnio()+a);
}

string Fecha::toString(){
    stringstream s;
    s<<"La fecha es: "<<endl;
	s<<"Dia: "<<dia<<endl;
	s<<"Mes: "<<mes<<endl;
	s<<"Anio: "<<anio<<endl;
    return s.str();
}

int main(){
	int a=0,b=0,c=0;
	cout<<"INGRESE LA FECHA "<<endl;
	do{
		cout<<"Dia: ";
		cin>>a;
    	if(a>31)cout<<"No existe una fecha con mas de 31 dias"<<endl;
    }while(a>31);
	do{
		cout<<"Mes: ";
		cin>>b;
    	if(b>12)cout<<"No existe una fecha con mas de 12 meses"<<endl;
    }while(b>12);
	cout<<"Anio: ";
	cin>>c;
	Fecha f1(a,b,c);
	
	cout<<endl<<f1.toString()<<endl;

	cout<<"Actualizando fecha... "<<endl;
	f1.agregarDias(45);

	f1.agregarMeses(3);

	f1.agregarAnios(4);

	cout<<f1.toString()<<endl;

	return 0;
}
