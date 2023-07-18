#include<bits/stdc++.h>
using namespace std;

class complexnumbers{
    private:
        int real;
        int imaginary;

    public:
    complexnumbers(int r, int i){
        this->real=r;
        this->imaginary=i;
    }

    void print(){
        cout<<real<<" "<<"+"<<" "<<"i"<<imaginary<<endl;
    }

    void sum(complexnumbers const& c2 ){
        int r=real+c2.real;
        int i=imaginary+c2.imaginary;

        real=r;
        imaginary=i;

    }

    void multiply(complexnumbers const& c2){
        int r=(real*c2.real)-(imaginary*c2.imaginary);
        int i=(real*c2.imaginary)+(imaginary*c2.real);

        real=r;
        imaginary=i;
        

    }

};