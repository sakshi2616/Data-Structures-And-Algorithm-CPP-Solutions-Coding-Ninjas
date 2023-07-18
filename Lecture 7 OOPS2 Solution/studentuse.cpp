#include<bits/stdc++.h>
using namespace std;
#include"studenttt.cpp"

int main(){
    char name[]="abcd";
    student s1(20,name); 
    
    s1.display(); //abcd 20
    student s2(s1);
    s2.name[0]='x';
    s1.display(); //xbcd 20
    s2.display(); //xbcd 20 //shallow copying
    // this is fixed by making our own copy constructor using deep copying
    /*
    name[3]='e';
    student s2(24,name);
    s2.display();

    s1.display();*/ //mistake if we do shallow copy
}

