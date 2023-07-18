
#include<iostream>
using namespace std;
class student{
    public :
    int rollno;
    private : //--> if i write this roll no is public but age is pvt
    int age;

    public : 

    ~student(){
        cout<<"deconstrucot called"<<endl;
    }

    //default constructor(as soon we write our own contrcutor we cant use defaltu)
    student(){
        cout<<"constructor called"<<endl;
    }
    //constructor should always have same name as class
    student(int rollno){
        cout<<"parameterized constructor called"<<endl;
        this->rollno=rollno;
    }

    student(int a, int r){
        //this is a pointer or special keyword
        cout<<"this :"<<this<<endl;
        cout<<"constructor 3 called"<<endl;
        age=a;
        rollno=r;
    }

    void display(){
        cout<<age<<" "<<rollno<<endl;
    }
    int getage(){
        return age;
    }

    void setage(int a, int password){
        if(password!=123){
            return;
        }
        if(a<0){
            return;
        }
        age=a;
    }


}; //syntax of class
//classes can be used as user defined data type

//student *s3=new student; - dynamically allocating object



