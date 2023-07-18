#include<iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl; //derefrences and gives the int
}

void incrementpointer(int *p){
    p=p+1;
    //cout<<p<<endl;
}

void increment(int *p){
    (*p)++;
}

int main(){
    int i=10;
    int *p=&i;
    print(p);
    cout<<p<<endl;
    incrementpointer(p);
    cout<<p<<endl; // stays the same cause it passes by value

    cout<<*p<<endl;
    increment(p);
    cout<<*p<<endl; //i gets incremented 
}