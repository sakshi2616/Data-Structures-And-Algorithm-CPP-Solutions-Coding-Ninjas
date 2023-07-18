#include<iostream>
using namespace std;

void increment(int **p){
    p++; //doesnt bring any change to actual double pointer
}

void increment2(int **p){
    *p=*p+1; //changes pointer(incremented by 4)
}

void increment3(int**p){
    **p=**p+1;//changes reflected here also
}

int main(){
    int i=10;
    int *p=&i;

    int **p2=&p;
    cout<<&p<<endl;
    cout<<p2<<endl; //same answer
    cout<<endl;


    cout<<p<<endl;
    cout<<*p2<<endl; 
    cout<<&i<<endl; //same answer of all 3(address of i)
    cout<<endl;


    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl; //all print 10; **=double derefrencing


}