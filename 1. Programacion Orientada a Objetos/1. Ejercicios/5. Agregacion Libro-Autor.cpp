#include<iostream>
#include<sstream>
using namespace std;

class Autor{
    private:
        string nombre;
        string apellido;
        string email;
    public:
        Autor(string,string,string);
        string toString();
};

class Libro{
    private:
        string titulo;
        Autor* autor;
        double precio;
        int cantidad;
    public:
        Libro(string, Autor*, double, int);
        string getTitulo();
        Autor* getAutor();
        double getPrecio();
        int getCantidad();
        void setAutor(Autor*);
        string toString();
};

Libro::Libro(string titulo, Autor* autor, double precio, int cantidad):titulo(titulo),autor(autor),precio(precio),cantidad(cantidad){}

Autor::Autor(string nombre, string apellido, string email):nombre(nombre),apellido(apellido),email(email){}

string Libro::getTitulo(){
    return titulo;
}
Autor* Libro::getAutor(){
    
    return autor;
}
double Libro::getPrecio(){
    return precio;
}
int Libro::getCantidad(){
    return cantidad;
}
void Libro::setAutor(Autor* autor){
    this->autor=autor;
}

string Libro::toString(){
    stringstream s;
    s<<"\nL I B R O"<<endl<<endl;
    s<<"Titulo: "<<titulo<<endl;
    s<<autor->toString();
    s<<"Precio: $"<<precio<<endl;
    s<<"Cantidad: "<<cantidad<<endl;
    return s.str();
}

string Autor::toString(){
    stringstream s;
    s<<"Autor: "<<endl;
    s<<"  *Nombre: "<<nombre<<endl;
    s<<"  *Apellido "<<apellido<<endl;
    s<<"  *Email: "<<email<<endl;
    return s.str();
}

int main(){
    Autor a1("Gabriel","Garcia Marquez","gabrielgarciamarquez@hotmail.com");

    Libro l1("Cien años de soledad",&a1,412.19,45);
    Libro l2("El coronel no tiene quien le escriba",&a1,201.87,34);
    
    cout<<l1.toString()<<endl;
    cout<<l2.toString()<<endl;
}