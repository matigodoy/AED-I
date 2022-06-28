#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<string> p1;
    p1.push("n");
    p1.push("e");
    p1.push("u");
    p1.push("q");
    p1.push("u");
    p1.push("e");
    p1.push("n");
    
    int n = p1.size()/2;

    stack<string> p2;

    for (int i = 0; i < n; i++){
        p2.push(p1.top());
        p1.pop();
    }
    
    n=p1.size();
    int n2=p2.size();

    if (n != n2){
        p1.pop();
    }

    bool c=true;
    while(!p1.empty() && c != false){
        if(p1.top() != p2.top()){
            c=false;
        }
        p1.pop();
        p2.pop();
    }

    if(c==true){
        cout<<"Si es palindromo "<<endl;
    }
    else{
        cout<<"No es palindromo "<<endl;
    }

    return 0;
}