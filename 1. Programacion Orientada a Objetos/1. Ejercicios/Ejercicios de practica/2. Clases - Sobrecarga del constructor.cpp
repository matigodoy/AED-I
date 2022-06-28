#include<iostream>
using namespace std;

class Tiempo{
	private:
		int horas,minutos,segundos;
	public:
		Tiempo(int,int,int);
		Tiempo(long);
		void mostrarDatos();
};

Tiempo::Tiempo(int _horas, int _minutos,int _segundos){
	horas = _horas;
	minutos = _minutos;
	segundos = _segundos;
}

Tiempo::Tiempo(long tiempo){
	horas = int (tiempo/10000);
	minutos = int ((tiempo-horas*10000)/100);
	segundos = int (tiempo - horas*10000-minutos*100);
}

void Tiempo::mostrarDatos(){
	cout<<"La hora es: "<<horas<<":"<<minutos<<":"<<segundos<<endl;
}

int main(){
	Tiempo t1(10,50,59);
	Tiempo t2(105059);
	t1.mostrarDatos();
	t2.mostrarDatos();
	return 0;
}
