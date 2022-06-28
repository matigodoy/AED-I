#include <iostream>
using namespace std;

class Punto{
    private:
        int x,y;
    public:
        Punto();
        void setPunto(int,int); //modifica
        int getPuntoX(); //lee
        int getPuntoY();
};

Punto::Punto(){
}

void Punto::setPunto(int _x,int _y){
	x = _x;
	y = _y;
}

int Punto::getPuntoX(){
	return x;
}

int Punto::getPuntoY(){
	return y;
}

int main(){
	Punto p1;
	p1.setPunto(20,50);
	cout<<"El punto es: ("<<p1.getPuntoX()<<","<<p1.getPuntoY()<<")"<<endl;
    return 0;
} 
