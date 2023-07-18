#include<iostream>
using namespace std;
int main(){
    int a[10];
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<&a[0]<<endl; //all give same output

    a[0]=5;
    cout<<*a<<endl; //a behaves like a pointer
    cout<<a+1<<endl; //address of element with 1st index
    
    a[1]=10;
    cout<<*(a+1)<<endl; // derefrencing next element in array

    int *p=&a[0];
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&a<<endl;
    cout<<&p<<endl;

}