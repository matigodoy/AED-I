#include<iostream>
using namespace std;
char letra;
int main()
{
	cout<<"Ingresa una letra wacho: ";
	cin>>letra;
	switch(letra){
		case 'a':
			cout<<letra<<" es una vocal";
			break;
		case 'A':
			cout<<letra<<" es una vocal";
			break;
		case 'e':
			cout<<letra<<" es una vocal";
			break;
		case 'E':
			cout<<letra<<" es una vocal";
			break;
		case 'i':
			cout<<letra<<" es una vocal";
			break;
		case 'I':
			cout<<letra<<" es una vocal";
			break;
		case 'o':
			cout<<letra<<" es una vocal";
			break;
		case 'O':
			cout<<letra<<" es una vocal";
			break;
		case 'U':
			cout<<letra<<" es una vocal";
			break;
		case 'u':
			cout<<letra<<" es una vocal";
			break;
		default:
			cout<<letra<<" es una consonante";
			break;
	}
}	

