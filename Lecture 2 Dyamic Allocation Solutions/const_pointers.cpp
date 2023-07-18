#include<iostream>
using namespace std;

void g(int const & a){
    //a++; not valid againt
}

void f(const int *p){
    //(*p)++; not valid ab
}

int main(){
    int const i=10;

    //int *p=&i; you can not store address of constant integer into a normal pointer
    int const *p=&i; //p is pointer to a constant integer
    

    int j=12;
    int const *p2=&j; //valid
    cout<<*p2<<endl;
    j++;
    cout<<*p2<<endl; //j ke thru jake change kr skte
    

    int k=12;
    int *p3=&j;
    f(p3);
    g(k);
}