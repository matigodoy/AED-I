#include<iostream>
#include<sstream>
using namespace std;

class Fecha{
    private:
        short dia;
        short mes;
        int anio;
    public:
        Fecha(short,short,int);
        void setDia(short);
        void setMes(short);
        void setAnio(int);
        string toString();
};

class Hora{
    private:
        short hora;
        short minuto;
        short segundo;
    public:
        Hora(short,short,short);
        void setHora(short);
        void setMinuto(short);
        void setSegundo(short);
        string toString();
};

class Evento{
    private:
        string nombre;
        Fecha fecha;
        Hora hora;
    public:
        Evento(string);
        void asignarFecha(short,short,int);
        void asignarHora(short,short,short);
        string toString();
};

Evento::Evento(string nombre):nombre(nombre),fecha(0,0,0),hora(0,0,0){}

void Evento::asignarFecha(short dia,short mes, int anio){
    this->fecha.setDia(dia);
    this->fecha.setMes(mes);
    this->fecha.setAnio(anio);
}

void Evento::asignarHora(short hora,short minuto,short segundo){
    this->hora.setHora(hora);
    this->hora.setMinuto(minuto);
    this->hora.setSegundo(segundo);
}

string Evento::toString(){
    stringstream s;
    s<<"Evento: "<<nombre<<endl;
    s<<fecha.toString();
    s<<hora.toString();
    return s.str();
}

Fecha::Fecha(short dia, short mes, int anio):dia(dia),mes(mes),anio(anio){}

void Fecha::setDia(short dia){
    this->dia=dia;
}

void Fecha::setMes(short mes){
    this->mes=mes;
}

void Fecha::setAnio(int anio){
    this->anio=anio;
}

string Fecha::toString(){
    stringstream s;
    s<<"  *Fecha: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    return s.str();
}

Hora::Hora(short hora,short minuto,short segundo):hora(hora),minuto(minuto),segundo(segundo){}

void Hora::setHora(short hora){
    this->hora=hora;
}

void Hora::setMinuto(short minuto){
    this->minuto=minuto;
}

void Hora::setSegundo(short segundo){
    this->segundo=segundo;
}

string Hora::toString(){
    stringstream s;
    s<<"  *Hora: "<<hora<<":"<<minuto<<":"<<segundo<<endl;
    return s.str();
}

int main(){
    Evento e1("Cumpleanios de Raul");
    e1.asignarFecha(24,8,2018);
    e1.asignarHora(22,40,00);
    cout<<e1.toString()<<endl;

    Evento e2("Samsung");
    e2.asignarFecha(10,12,2020);
    e2.asignarHora(13,00,00);
    cout<<e2.toString()<<endl;
}
