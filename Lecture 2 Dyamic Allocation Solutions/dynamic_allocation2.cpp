#include<iostream>
using namespace std;
int main(){
    int *p=new int;
    
    //manually deleting heap memory 
    //"delete" keyword
    delete p; //8 bytes will remain, 4 bytes of heap memory will be deleted
    p=new int;
    delete p; //p del nahi hua hai, woh jise point kar rha woh delete hua

    p=new int[100];
    delete []p; // deleting array

    /*while(true){
        int i=10
    } this is an infinte loop cause everytime we exit loop
    scope of i finished and next time new i is created*/

    // if we write int *p=new int; 12 bytes are allocated, 4 in heap and 8 n stack
    /*while(true){
        int *p=new int;
    }*/
    // everytime we enter loop new int created, sometime it will finish caue no more memory will be left

}