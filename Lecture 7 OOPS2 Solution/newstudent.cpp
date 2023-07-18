#include<bits/stdc++.h>
using namespace std;

class student{
    public:

    int age;
    const int rollno; //change nahi ho payega
    int &x; //age refrencee variable

    student(int r, int age): rollno(r), age(age), x(this->age){
        //rollno=r;
    }
};