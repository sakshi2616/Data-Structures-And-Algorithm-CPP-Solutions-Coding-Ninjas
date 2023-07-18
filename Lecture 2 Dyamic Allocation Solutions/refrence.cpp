#include<iostream>
using namespace std;

void increment(int &n){
    n++;
}
//bad practice
int & f(int n){
    int a=n;
    return a;
}
//bad practice
int *f2(){
    int i=10;
    return &i;
}

int main(){
    int *p=f2(); //wrong because i to us function ka local variable hai

    int i=10;
    /*int j=i;
    i++;
    cout<<j<<endl;*/ //no difference in j due to i;independent

    //to make a j such that no special memory is allocated
    //for it and it has the same address as that of i we make it a refrence variable

    int& k1=f(i); //as we can pass data by refrence we can also recieve data by refrence
    // int& k=f(i); this is wrong because a ka scope is only till memory


    increment(i);
    cout<<i<<endl; //no change was reflected when increment(int n), we saw earlier
    //but agar yahan refrence krdete to value change ho jati
    //agar increment ka n refrence variable hota to neeche changes reflect hojayenge
    //change reflected when increment(int &n)
    //pass by value ki jagah pass by refrence kar rhe


    int &j=i; //syntax for refrence variable, j and i will share same memory address
    i++;
    cout<<i<<endl;
    cout<<j<<endl; 
    j++;
    cout<<i<<endl;
    cout<<j<<endl; //changes reflected

    int k=100;
    j=k;
    cout<<i<<endl;
    cout<<j<<endl; //address same, value changed for both

}