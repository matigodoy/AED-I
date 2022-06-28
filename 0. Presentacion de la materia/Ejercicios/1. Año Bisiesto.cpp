#include<iostream>
using namespace std;
int main(){
	int a;
	cout<<"Introduce anio: ";
	cin>>a;
	if(a%4== && a%100!=0 || a%400==0) cout << "Si es bisiesto" << endl;
	else cout << "No es bisiesto" << endl;
	return 0;
}

