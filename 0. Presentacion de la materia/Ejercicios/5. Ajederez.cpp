#include<iostream>
using namespace std;
int main(){
	int N=8;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<(((i+j)%2)?" # ":"o ");
		}
		cout<<endl;
	}
}
