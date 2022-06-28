#include<iostream>
#include<sstream>
using namespace std;

class Punto{
    private:
        int x;
        int y;
    public:
        Punto(int,int);
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
        string toString();
};

Punto::Punto(int x,int y):x(x),y(y){}

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

string Vehiculo::toString(){
    stringstream s;
    s<<"Nombre: "<<nombre<<endl;
    s<<posicion.toString()<<endl;
    return s.str();
}

int main(){
    Vehiculo v1("Francisco");
    cout<<v1.toString()<<endl;
    v1.moverA(34,65);
    cout<<v1.toString()<<endl;

    Vehiculo v2("Federico");
    v2.moverA(75,90);
    cout<<v2.toString()<<endl;
}