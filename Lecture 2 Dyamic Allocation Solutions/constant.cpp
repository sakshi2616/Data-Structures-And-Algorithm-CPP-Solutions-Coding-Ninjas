#include<iostream>
using namespace std;

int main(){
    const int i=10; //constant integer
    int const i2=10; //same thing

    //i=12; //changing the storage // wont work if int is const

    //const int l;
    //l=10; //this is also not allowed, usi time initialize krna papdega

    int j=12;
    const int &k=j; //constant refrence from a non const integer
    //k++; not valid
    j++; //j ke thru jake change kr skte hai but k ke thru jake change nahi kr skte
    //but changes to k mei bhi ayenge

    cout<<j<<" "<<k; 

    //constant refrence from a const int
    int const j2=12;
    int const &k2=j2;
    //j2++;
    //k2++; both invalid operations

    //refrence from a const integer
    int const j3=123;
    //int &k3=j3; not valid, we only have read access

    
}