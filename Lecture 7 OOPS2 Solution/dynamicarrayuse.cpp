#include<iostream>
using namespace std;
#include"dynamicarray.cpp"

int main(){
    dynamicarray d1;

    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();
    
    


    dynamicarray d2(d1); //copyconstructor called (shallow copying);
    dynamicarray d3;
    d3=d1; //copy assignment operator(also shallow copying)
    d1.add(0,100);
    d1.print();
    d3.print(); //khud wala cchala ab
    d2.print(); //ab humara wala chala so no change



}