#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;

class Punto{
    private:
        int x;
        int y;
    public:
        Punto(int,int);
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        string toString();
};

class Vehiculo{
    private:
        string nombre;
        Punto posicion;
    public:
        Vehiculo(string);
        void moverA(int,int);
        double distancia(int,int);
        string toString();
};

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

string Punto::toString(){
    stringstream s;
    s<<"Punto: ("<<x<<" ; "<<y<<")"<<endl;
    return s.str();
}

Vehiculo::Vehiculo(string nombre):nombre(nombre),posicion(0,0){}

void Vehiculo::moverA(int x, int y){
    this->posicion.setX(x);
    this->posicion.setY(y);
}

double Vehiculo::distancia(int x2,int y2){
    double distancia=0;
	distancia = sqrt((this->posicion.getX() - x2)*(this->posicion.getX() - x2 ) + (this->posicion.getY() - y2)*(this->posicion.getY() - y2));
	return distancia;
}

string Vehiculo::toString(){
    stringstream s;
    s<<"Nombre: "<<nombre<<endl;
    s<<posicion.toString()<<endl;
    return s.str();
}

int main(){
    Vehiculo v1("Francisco");
    cout<<v1.toString();
    v1.moverA(34,65);
    cout<<v1.toString();

    Vehiculo v2("Federico");
    v2.moverA(75,90);
    cout<<v2.toString();

    cout<<"La distancia entre los dos vehiculos es: "<<v1.distancia(75,90)<<endl;
}