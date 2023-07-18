#include<bits/stdc++.h>
using namespace std;

#include"fraction_class.cpp"

int main(){
    fraction f1(10,2);
    fraction f2(15,4);

    const fraction f3; //garbage value rkh di constructor ne n and d mei

    /*f3.getnum();
    f3.getdeno();
    f3.setnum(10); all three statements show error */

    //you can only call contant functions for constant objects(which dont change any property)
    //constant mark krdia ab pehle do no error

    f3.getnum();
    f3.getdeno();
    
}