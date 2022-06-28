#include<iostream>
using namespace std;
int factorial(int);
int factorialrec(int);
int main(){
	int n;
	cout<<"Ingrese el numero ";
	cin>>n;
	cout<<"El factorial es: "<<factorial(n)<<endl;
	cout<<"El factorial es: "<<factorialrec(n)<<endl;
	return 0;
}
int factorial(int n){
	int num=1;
	for(int i=1;i<n+1;i++){
		num=num*i;
	}
	return num;
}
int factorialrec(int n){
	if(n==0)return 1;
	else return n*factorialrec(n-1);
}
