#include<bits/stdc++.h>
using namespace std;
#include"linkedlist_Stack.cpp"

int main(){
    stackusingll<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    
    //treated as ascii values
    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.getsize()<<endl;
    cout<<s.isempty()<<endl;

}