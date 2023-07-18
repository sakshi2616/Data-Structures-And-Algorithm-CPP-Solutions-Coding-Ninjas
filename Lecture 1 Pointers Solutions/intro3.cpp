#include<iostream>
using namespace std;
int main(){
    int i;
    cout<<i<<endl; //garbage value printed

    i++;
    cout<<i<<endl; //garbage value increased

    int *p;
    cout<<p<<endl; 
    cout<<*p<<endl; //garbage at garbage address value printed
    (*p)++;
    cout<<*p<<endl; // dont do

    // to avoid random values, initiate it with 0
    //int *p=0
}