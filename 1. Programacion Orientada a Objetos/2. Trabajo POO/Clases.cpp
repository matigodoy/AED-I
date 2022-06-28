#include <iostream>
#include<sstream>
using namespace std;

//clase padre: Inicio
class Inicio{
	private:
		string titulo;
		int hora;
		int minuto;
	public:
		Inicio(string,int,int);
		string toString();
};

Inicio::Inicio(string titulo,int hora,int minuto):titulo(titulo),hora(hora),minuto(minuto){}

string Inicio::toString(){
	stringstream s;
	s<<"Titulo: "<<titulo<<endl;
	s<<"Hora: "<<hora<<":"<<minuto<<endl;
	return s.str();
}

//clase hija: Entero
class Entero:public Inicio{
	private:
		long entero;
		long enteros[50];
		int cantidad;
	public:
		Entero(string,int,int,long,int);
		void setEnteros();
		string toString();
};

Entero::Entero(string titulo,int hora,int minuto,long entero,int cantidad):Inicio(titulo,hora,minuto),entero(entero),cantidad(cantidad){}

void Entero::setEnteros(){
	do{
		cout<<"Ingrese la cantidad de numeros enteros que quiere ingresar: ";
		cin>>cantidad;
		if(cantidad>50 || cantidad<1)cout<<"Se pueden ingresar como maximo 50 numeros "<<endl;
	}while(cantidad>50 || cantidad<1);
	for(int i=0;i<cantidad;i++){
		cout<<"Ingrese el entero numero "<<i+1<<":";
		cin>>enteros[i];
	}
}

string Entero::toString(){
	cout<<Inicio::toString();
	stringstream s;
	s<<"Numero Entero: "<<entero<<endl;
	s<<"Vector con Numeros Enteros: "<<endl;
	for(int i=0;i<cantidad;i++){
		s<<"Numero "<<i+1<<": "<<enteros[i]<<endl;
	}
	return s.str();
}

//clase hija: Decimal
class Decimal:public Inicio{
	private:
		double decimal;
		double decimales[50];
		int cantidad;
	public:
		Decimal(string,int,int,double,int);
		void setDecimales();
		string toString();
		int matoi();
};

Decimal::Decimal(string titulo,int hora,int minuto,double decimal,int cantidad):Inicio(titulo,hora,minuto),decimal(decimal),cantidad(cantidad){}

void Decimal::setDecimales(){
	do{
		cout<<"Ingrese la cantidad de numeros decimales que quiere ingresar: ";
		cin>>cantidad;
		if(cantidad>50 || cantidad<1)cout<<"Se pueden ingresar como maximo 50 numeros "<<endl;
	}while(cantidad>50 || cantidad<1);
	for(int i=0;i<cantidad;i++){
		cout<<"Ingrese el decimal numero "<<i+1<<":";
		cin>>decimales[i];
	}
}

string Decimal::toString(){
	cout<<Inicio::toString();
	stringstream s;
	s<<"Numero Decimal: "<<decimal<<endl;
	s<<"Vector con Numeros Decimales: "<<endl;
	for(int i=0;i<cantidad;i++){
		s<<"Numero "<<i+1<<": "<<decimales[i]<<endl;
	}
	return s.str();
}

//clase hija: Caracter
class Caracter:public Inicio{
	private:
		char caracter[20];
		char caracteres[20][50];
		int cantidad;
	public:
		Caracter(string,int,int,int);
		void setCaracter();
		void setCaracteres();
		string toString();
};

Caracter::Caracter(string titulo,int hora,int minuto,int cantidad):Inicio(titulo,hora,minuto),cantidad(cantidad){}

void Caracter::setCaracter(){
	cout<<"Ingrese el caracter: ";
	cin>>caracter;
}

void Caracter::setCaracteres(){
	do{
		cout<<"Ingrese la cantidad de caracteres que quiere ingresar: ";
		cin>>cantidad;
		if(cantidad>50 || cantidad<1)cout<<"Se pueden ingresar como maximo 50 numeros "<<endl;
	}while(cantidad>50 || cantidad<1);
	for(int i=0;i<cantidad;i++){
		cout<<"Ingrese el caracter numero "<<i+1<<":";
		cin>>caracteres[i];
	}
}

string Caracter::toString(){
	cout<<Inicio::toString();
	stringstream s;
	s<<"Caracter: "<<caracter<<endl;
	s<<"Vector con Caracteres: "<<endl;
	for(int i=0;i<cantidad;i++){
		s<<"Caracter "<<i+1<<": "<<caracteres[i]<<endl;
	}
	return s.str();
}

//clase hija: Cadena_Caracteres
class Cadena_Caracteres:public Inicio{
	private:
		string cadcaracter;
		string cadcaracteres[50];
		int cantidad;
	public:
		Cadena_Caracteres(string,int,int,string,int);
		void setCaracteres();
		string toString();
};

Cadena_Caracteres::Cadena_Caracteres(string titulo,int hora,int minuto,string cadcaracter,int cantidad):Inicio(titulo,hora,minuto),cadcaracter(cadcaracter),cantidad(cantidad){}

void Cadena_Caracteres::setCaracteres(){
	do{
		cout<<"Ingrese la cantidad de caracteres que quiere ingresar: ";
		cin>>cantidad;
		if(cantidad>50 || cantidad<1)cout<<"Se pueden ingresar como maximo 50 numeros "<<endl;
	}while(cantidad>50 || cantidad<1);
	for(int i=0;i<cantidad;i++){
		cout<<"Ingrese el caracter numero "<<i+1<<":";
		cin>>cadcaracteres[i];
	}
}

string Cadena_Caracteres::toString(){
	cout<<Inicio::toString();
	stringstream s;
	s<<"Caracter: "<<cadcaracter<<endl;
	s<<"Vector con Caracteres: "<<endl;
	for(int i=0;i<cantidad;i++){
		s<<"Caracter "<<i+1<<": "<<cadcaracteres[i]<<endl;
	}
	return s.str();
}

int main(){
	Entero* ent;
	Entero e1("Enteros",10,45,568354,0);
	ent = &e1;
	ent->setEnteros();
	cout<<ent->toString();
	
	Decimal* dec;
	Decimal d1("DECIMALES",10,45,432.654,0);
	dec = &d1;
	dec->setDecimales();
	cout<<dec->toString();
	
	Caracter* car;
	Caracter c1("Caracteres",10,45,0);
	car = &c1;
	car->setCaracter();
	car->setCaracteres();
	cout<<car->toString();
	
	Cadena_Caracteres* cadcar;
	Cadena_Caracteres cad1("Caracteres",10,45,"Hola Mundo",0);
	cadcar = &cad1;
	cadcar->setCaracteres();
	cout<<cadcar->toString();
	
    return 0;
}
