#include<bits/stdc++.h>
using namespace std;
#include"polynomicalclass.cpp"

int main(){
    int n;
    cin>>n;
    int *degree1=new int[n];
    int *coeff1=new int[n];
    polynomial p1;

    for(int i=0;i<n;i++){
        cin>>degree1[i];
    }

    for(int i=0;i<n;i++){
        cin>>coeff1[i];
    }

    for(int i=0;i<n;i++){
        p1.setcoeff(degree1[i], coeff1[i]);
    }

    int m;
    cin>>m;
    int *degree2=new int[m];
    int *coeff2=new int[m];
    polynomial p2;

    for(int i=0;i<m;i++){
        cin>>degree2[i];
    }

    for(int i=0;i<m;i++){
        cin>>coeff2[i];
    }

    for(int i=0;i<m;i++){
        p2.setcoeff(degree2[i], coeff2[i]);
    }

    int choice;
    cin>>choice;

    if(choice==1){
        polynomial p3;
        p3=p1+p2;
        p3.print();
    }

    else if(choice==2){
        polynomial p3;
        p3=p1-p2;
        p3.print();
    }

    else if(choice==3){
        polynomial p3;
        p3=p1*p2;
        p3.print();
    }

    
}