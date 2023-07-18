#include<bits/stdc++.h>
using namespace std;

class polynomial{
    int *degcoeff;
    int capacity;

    public:

    //default constructor
    polynomial(){
        degcoeff=new int[5];
        for(int i=0;i<5;i++){
            degcoeff[i]=0;
        }
        capacity=5;
    }

    //print
    void print(){
        for(int i=0;i<capacity;i++){
            if(degcoeff[i]!=0){
                cout<<degcoeff[i]<<"x"<<i<<" ";
            }
        }
    }

    //setcoeffecient
    void setcoeff(int d, int c){
        if(d>=capacity){
            int *newc=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newc[i]=degcoeff[i];
            }
            for(int i=capacity;i<(2*capacity);i++){
                newc[i]=0;
            }
            delete []degcoeff;
            degcoeff=newc;
            capacity*=2;
        }
        degcoeff[d]=c;
    }

    //copyconstructor
    polynomial(polynomial const &p){
        this->capacity=p.capacity;
        this->degcoeff=new int[p.capacity];
        for(int i=0;i<capacity;i++){
            this->degcoeff[i]=p.degcoeff[i];
        }
    }

    //+
    polynomial operator+(polynomial const &p){
        polynomial pnew;
        int newcap=max(capacity, p.capacity);
        for(int i=0;i<newcap;i++){
            if(i<capacity && i<p.capacity){
                
                pnew.setcoeff(i,degcoeff[i]+p.degcoeff[i]);
            }
            else if(i<capacity){
                
                pnew.setcoeff(i,degcoeff[i]);
            }
            else{
                pnew.setcoeff(i,p.degcoeff[i]);
            }
        }
        return pnew;
    }

    //-
    polynomial operator-(polynomial const &p){
        polynomial pnew;
        int newcap=max(capacity, p.capacity);
        for(int i=0;i<newcap;i++){
            if(i<capacity && i<p.capacity){
                
                pnew.setcoeff(i,degcoeff[i]-p.degcoeff[i]);
            }
            else if(i<capacity){
                
                pnew.setcoeff(i,degcoeff[i]);
            }
            else{
                pnew.setcoeff(i,p.degcoeff[i]);
            }
        }
        return pnew;
    }

    //*
    polynomial operator*(polynomial const &p){
        int newcap=capacity+p.capacity;
        polynomial pnew;
        
        for(int i=0;i<capacity;i++){
            for(int j=0;j<p.capacity;j++){
                pnew.setcoeff(i+j, pnew.degcoeff[i+j]+degcoeff[i]*p.degcoeff[j]);
            }
        }
        pnew.capacity=newcap;
        return pnew;
    }

    //=
    void operator=(polynomial const &p){
        int *newdeg=new int[p.capacity+1];
        for(int i=0;i<p.capacity;i++){
            newdeg[i]=p.degcoeff[i];
        }
        this->degcoeff=newdeg;
        this->capacity=p.capacity;
    }
};