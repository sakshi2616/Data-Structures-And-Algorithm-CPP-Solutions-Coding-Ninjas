#include<iostream>
using namespace std;

int main(){
    int i=10;
    int j=21;
    int const *p=&i; //valid, p is a pinter pointing towards a constnt int

    p=&j;

    int * const p2=&i; //constant pointer
    (*p2)++; //valid
    // p2=&j; //not valid

    int const * const p3=&i; //constant pointer to a constant integer
    //p3=&j invalid
    //(*p3)++ invalid
}