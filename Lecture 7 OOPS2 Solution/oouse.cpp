#include<bits/stdc++.h>
using namespace std;

#include"operatoroverloading.cpp"

int main(){
    fraction f1(10,3);
    fraction f2(5,2);

    fraction f3=f1.add(f2);
    f1.print();
    f2.print();
    f3.print();

    //fraction f4=f1+f2 ----> f1(this) and f2(is passed as argument)
    fraction f4=f1+f2;
    f4.print();

    fraction f5=f1*f2;
    f5.print();

    if(f1==f2){
        cout<<"equal"<<endl;
    }
    else{
        cout<<"not equal"<<endl;
    }
    fraction f6;
    cout<<"oo 2"<<endl;

    //using pre increment
    f1.print();
    //++f1;
    //f1.print();
    //f6=++f1;
    //f6.print();

    //fraction f7=++(++f1);
    //f1.print(); //prints 6 only instead of 7 if & not added
    //f7.print();

    //using post increment (nesting not allowed in post increment)
    /*fraction f8=f1++;
    f1.print();
    f8.print();*/

    f1+=f2;
    f1.print();
    f2.print();


}