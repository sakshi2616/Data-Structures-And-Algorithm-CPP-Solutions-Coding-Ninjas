#include<iostream>
using namespace std;

int main(){
    int i=65;
    char c=i;
    cout<<c<<endl; //should print 'a'

    int *p=&i;
    // char *pc=p; doesnt work
    char*pc=(char*)p;  //implicit typecasting
    cout<<*p<<endl;
    cout<<*pc<<endl; //gives a

    cout<<*(pc+1)<<endl;
    cout<<*(pc+2)<<endl;
    cout<<*(pc+3)<<endl; //all three gave null character

    cout<<p<<endl;
    cout<<pc<<endl; // printing character pointer prints the character itself
    
    //if we do the opposite and implicitely typecast char pointer as int,
    // it will read not 1 but 4 bytes and print garbage value also
    

}