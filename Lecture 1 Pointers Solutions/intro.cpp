#include<iostream>
using namespace std;
int main(){
    int i=10;
    //prints the address of i
    cout<<&i<<endl; 
    int *p=&i; 
    cout<<p<<endl; //pointer p stores address of i
    cout<<*p<<endl; //derefrence operator- gives the value pointed by p

    float f=10.2;
    float *pf=&f;
    
    double d=122.45;
    double *pd=&d;

    cout<<f<<" "<<pf<<endl;
    cout<<d<<" "<<pd<<endl;

}