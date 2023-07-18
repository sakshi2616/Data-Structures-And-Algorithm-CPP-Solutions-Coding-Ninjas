#include<bits/stdc++.h>
using namespace std;
#include "student.cpp"

int main(){
    student s1(10,101);
    cout<<"address "<< &s1<<endl;

    student s2(20);
    s2.display();

    /*
    student s1;
    //if i made my own constrcutors (like 2 and 3) then default wont be available and if i coment first self made one then this will show error


    s1.display();

    student s2;

    student *s3=new student;
    (*s3).display();

    cout<<"parameterzised constructors demo"<<endl;
    student s4(10);
    s4.display();
    //for every object only one constructor is called and that too when it is made

    student *s5=new student(101);
    (*s5).display();

    student s6(20,102);
    s6.display();*/

}