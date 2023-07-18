#include<iostream>
using namespace std;
class fraction{

    private:
        int numerator;
        int denominator;

    public:

    fraction(){

    }

    fraction(int n, int d){
        numerator=n;
        denominator=d;
    }

    int getnum()const {
        return numerator;
    }

    int getdeno() const{
        return denominator;
    }

    void setnum(int n){
        numerator=n;
    }

    void setdeno(int d){
        denominator=d;
    }

    void print()const {
       cout<< this->numerator <<"/"<<this->denominator <<endl;

    }

    //f1=f1+f2

    void simplify(){
        int gcd=1;
        int j=min(numerator, denominator);
        for(int i=1;i<=j;i++){
            if(numerator%i==0 && denominator%i==0){
                gcd=i;
            }
        }

        numerator=numerator/gcd;
        denominator=denominator/gcd;
    }

    fraction add(fraction const& f2){
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;

        int num= x*numerator+(y*f2.numerator);

        //numerator=num;
        //denominator=lcm;
        fraction fnew(num,lcm);
        fnew.simplify(); //means this ke upar simplify call krlo
        //simplying the fraction
        return fnew;

    }

    fraction operator+(fraction const& f2)const{
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num= x*numerator+(y*f2.numerator);

        fraction fnew(num,lcm);
        fnew.simplify(); 
        return fnew;
    }

    //multiply- f1=f1*f2
    void multiply(fraction f2){
        numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;

        simplify();
    }

    fraction operator*(fraction const &f2)const{
        int n=numerator*f2.numerator;
        int d=denominator*f2.denominator;
        fraction fnew(n,d);
        fnew.simplify();
        return fnew;
    }

    bool operator==(fraction const &f2)const{
        return(numerator==f2.numerator && denominator==f2.denominator);
    }


    //pre-increment
    fraction& operator++(){
        numerator=numerator+denominator;
        simplify();

        return *this;
    }

    //postincrement
    fraction operator++(int){
        fraction fnew(numerator, denominator);
        numerator=numerator+denominator;
        simplify();
        fnew.simplify();
        return fnew;

    }

    //=+ operator(nesting allowed)
    fraction& operator+=(fraction const &f2){
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num= x*numerator+(y*f2.numerator);

        numerator=num;
        denominator=lcm;
        simplify();
        return *this;
    }

};
