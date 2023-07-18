#include<iostream>
using namespace std;
int main(){
    int i=10;
    int*p=&i;
    cout<<p<<endl;
    cout<<*p<<endl;

    p=p+1; // starts pointing to next integer
    cout<<p<<endl; // adds 4 bytes
    cout<<*p<<endl;

    //p-- (starts pointing to last integer)
    p=p-1;
    cout<<p<<endl; 
    cout<<*p<<endl;
}