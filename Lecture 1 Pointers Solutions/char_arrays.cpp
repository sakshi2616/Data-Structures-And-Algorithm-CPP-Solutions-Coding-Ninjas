#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3};
    char b[]="abcs";
    cout<<a<<endl; //will print address of 0th element of array
    cout<<b<<endl; //will go there and read the content


    char *c=&b[0];
    cout<<c<<endl; //char pointer behaves like char array, goes there and prints actual content

    char c1='a';
    char *pc=&c1;
    cout<<c1<<endl;
    cout<<pc<<endl; // prints till it finds null character (imp)

    char str[]="abcde";
    char *pstr="abcde"; // points to a temp memory (wrong)
    

}