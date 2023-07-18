#include<bits/stdc++.h>
using namespace std;
#include "complexclass.cpp"


int main(){
    int reala, imaa, realb, imab;

    cin>>reala>>imaa;
    cin>>realb>>imab;

    complexnumbers c1(reala, imaa);
    complexnumbers c2(realb, imab);

    int choice;
    cin>>choice;

    if(choice==1){
        c1.sum(c2);
        c1.print();
    }

    else if (choice==2){
        c1.multiply(c2);
        c1.print();
    }

    else{
        return 0;
    }
}