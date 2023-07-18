#include<iostream>
using namespace std;
int main(){
    int i=10;
    int *p=&i;

    cout<<sizeof(p)<<endl; //sometimes 4 sometimes 8
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    i++;
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<*p<<endl; //changes reflected

    int a=i; //= int a=*p(same meaning)
    a++;
    cout<<a<<endl;
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<*p<<endl; //no change in p or i
    
    i=12;
    *p=23;
    cout<<*p<<endl;
    cout<<i<<endl;

    (*p)++;
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<*p<<endl; //changes visible

    int *q=p; //q will also point towards i
    //*p,*q, i will give same value
    
}