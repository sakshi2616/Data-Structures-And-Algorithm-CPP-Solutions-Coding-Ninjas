#include<bits/stdc++.h>
using namespace std;

#include "student.cpp"

int main(){

    student s1(1,100);
    student s2(2,101);
    student *s3=new student(3,1003);

    s2=s1;
    *s3=s1;
    s2=*s3;

    delete s3; //because dynamically allocated
    //deconstrucot called automatically

    /*student s1(10,1001);
    cout<<"s1 ";
    s1.display();

    student s2(s1);
    cout<<"s2 ";
    s2.display();

    //no constructor called message for s2 as our constructor is not used but copy constructor is

    student *s3=new student(20,1009);
    student s4(*s3);

    student *s5=new student(*s3);

    student *s6=new student(s1);*/
}