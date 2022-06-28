#include<iostream>
#include<cmath>
#include<sstream>
using namespace std;

class Punto{
	private:
		int x,y;
	public:
		Punto();
		Punto(int,int);
		int getX();
		int getY();
		void setX(int);
		void setY(int);
		double distancia(int,int);
		string toString();
};
Punto::Punto(){
}
Punto::Punto(int x,int y):x(x),y(y){}

int Punto::getX(){
	return x;
}
int Punto::getY(){
	return y;
}
void Punto::setX(int x){
	this->x=x;
}
void Punto::setY(int y){
	this->y=y;
}
double Punto::distancia(int x2,int y2){
	double distancia=0;
	distancia = sqrt((x - x2)*(x - x2 ) + (y - y2)*(y - y2));
	return distancia;
}
string Punto::toString(){
    stringstream s;
	s<<"El punto ingresado es: ("<<this->getX()<<";"<<this->getY()<<")"<<endl;
    return s.str();
}
int main(){
	int x1=20,y1=40;
	Punto p1(x1,y1);
	cout<<p1.toString()<<endl;

	int x2=50,y2=10;
	Punto p2(x2,y2);
	cout<<p2.toString()<<endl;

	cout<<"La distancia entre el punto ("<<p1.getX()<<";"<<p1.getY()<<") y el punto ("<<p2.getX()<<";"<<p2.getY()<<") es:"<<p1.distancia(p2.getX(),p2.getY())<<endl;

	return 0;
}