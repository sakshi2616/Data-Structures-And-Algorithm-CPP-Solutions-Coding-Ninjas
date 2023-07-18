#include<iostream>
using namespace std;

#include "student.cpp"

int main(){
    //creating objects statically
    student s1;
    student s2;
    student s3,s4,s5;

    //create objects dynamically
    student *s6=new student;

    //setting properties: s1.rolno=19

    //s1.age=24;
    s1.rollno=101;
    cout<<s1.getage()<<endl;
    cout<<s1.rollno<<endl;

    s1.display();

    //(*s6).age=23;
    (*s6).rollno=104;

    //s6 -> age=23;
    s6 -> rollno=104;

    cout<<s6->getage()<<endl;

    s6 -> display();

}