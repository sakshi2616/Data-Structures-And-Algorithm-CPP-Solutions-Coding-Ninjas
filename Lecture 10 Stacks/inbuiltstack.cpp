#include<bits/stdc++.h>
using namespace std;

#include <stack>

int main(){
    stack<int> s; 

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    //same as humara push fn

    //iska pop function bas delete krta not return(void function)
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    //top bhi same hai idhar
    cout<<s.size()<<endl;
    //size same 
    cout<<s.empty()<<endl;
    //isempty ka naam idhar empty()

}