#include<iostream>
using namespace std;

class Figura{
	protected:
		double base;
		double altura;
	public:
		Figura(double,double);
		virtual double getSuperficie();
};

class Cuadrado:public Figura{
	public:
		Cuadrado(double);
		double getSuperficie();
};

class Rectangulo:public Figura{
	public:
		Rectangulo(double,double);
		double getSuperficie();
};

class Triangulo:public Figura{
	public:
		Triangulo(double,double);
		double getSuperficie();
};

Figura::Figura(double base,double altura):base(base),altura(altura){}

double Figura::getSuperficie(){
	return 0.0;
}

Cuadrado::Cuadrado(double base):Figura(base,base){}

double Cuadrado::getSuperficie(){
	return base*base;
}

Rectangulo::Rectangulo(double base,double altura):Figura(base,altura){}

double Rectangulo::getSuperficie(){
	return base*altura;
}

Triangulo::Triangulo(double base,double altura):Figura(base,altura){}

double Triangulo::getSuperficie(){
	return (base*altura)/2;
}

int main(){
	Figura *f;
	Cuadrado c1(5);
	f=&c1;
	cout<<"La superficie del cuadrado es: "<<f->getSuperficie()<<endl<<endl;
	
	Rectangulo r1(5.7,8);
	f=&r1;
	cout<<"La superficie del rectangulo es: "<<f->getSuperficie()<<endl<<endl;
	
	Triangulo t1(9.5,2.7);
	f=&t1;
	cout<<"La superficie del triangulo es: "<<f->getSuperficie()<<endl<<endl;
	return 0;
}