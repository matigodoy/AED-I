#include<iostream>
using namespace std;

class CuentaBancaria{
	private:
		int numeroCuenta;
		double balance;
	public:
		CuentaBancaria(int,double);
		int getNumeroCuenta();
		double getBalance();
		void setBalance(double);
		double credito(double);
		double debito(double);
};

CuentaBancaria::CuentaBancaria(int numeroCuenta, double balance):numeroCuenta(numeroCuenta),balance(balance){}

int CuentaBancaria::getNumeroCuenta(){
	return numeroCuenta;
}

double CuentaBancaria::getBalance(){
	return balance;
}

void CuentaBancaria::setBalance(double _balance){
	balance = _balance;
}

double CuentaBancaria::credito(double b){
	this->setBalance(balance+b);
	return balance;
}

double CuentaBancaria::debito(double b){
	if(balance==0)return -1;
	else if(b>balance)return -2;
	else return balance-b;
}

int main(){
	int a=0;
	cout<<"Ingrese un numero de cuenta: ";
	cin>>a;

	CuentaBancaria c1(a,5000);

	cout<<"Su numero de cuenta es: "<<c1.getNumeroCuenta()<<endl;
	cout<<"Su balance es: $"<<c1.getBalance()<<endl;

	cout<<"Ingresar $200 a la cuenta. Saldo total: "<<c1.credito(200)<<endl;

	cout<<"Extraer $200 de la cuenta. ";
	if(c1.debito(200) == -1) cout<<"No puede extraer porque tiene saldo $0"<<endl;
	else if (c1.debito(200) == -2) cout<<"No puede extraer mas $ de los que tiene. Su saldo es: $"<<c1.getBalance()<<endl;
	else{
		c1.setBalance(c1.debito(200));
		cout<<"Extraccion confirmada. Su nuevo saldo es: $"<<c1.getBalance()<<endl;
	}
}
