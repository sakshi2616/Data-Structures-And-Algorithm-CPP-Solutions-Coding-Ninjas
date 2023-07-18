#include<bits/stdc++.h>
using namespace std;

class student{

    static int totals; //total no of students present
    //static property-belong to class not object
    //to access write ---- student ::totals;

    public:

    int rollno;
    int age;

    student(){
        totals++;
    }

    int getrollno(){
        return rollno;
    }

    //like variables, functions can also be static
    static int gettotals(){
        return totals;
    }
    
};

//initialisation of static properties is outside class
int student:: totals=0; //initalise static data members