#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> p1;
    stack<int> p2;
    int temp=0;

    int v[] = {5, 10, 2, 6, 15, 21, 12, 3, 7, 16};
    int n = sizeof(v)/sizeof(v[0]);

    for (int i = 0; i < n; i++){
        p1.push(v[i]);
    }
    
    while(! p1.empty()){
        temp = p1.top();
        p1.pop();
        while(! p2.empty() && temp > p2.top()){
            p1.push(p2.top());
            p2.pop();
        }
        p2.push(temp);
    }

    while(! p2.empty()){
        cout<<p2.top()<<endl;
        p2.pop();
    }

    return 0;
}