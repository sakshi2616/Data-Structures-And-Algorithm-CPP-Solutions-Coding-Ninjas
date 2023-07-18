#include<bits/stdc++.h>
using namespace std;

class stackusingarray{
    int *data;
    int nextindex;
    int capacity;

    public:

    stackusingarray(int totalsize){
        data=new int[totalsize];
        nextindex=0;
        capacity=totalsize;
    } //fixed size ka array
    

    int size(){
        return nextindex;
    }

    bool isempty(){
        return nextindex==0; //0==0 true else false
    }

    void push(int element){
        if(nextindex==capacity){
            cout<<"stack is full "<<endl;
            return;
        }
        data[nextindex]=element;
        nextindex++;
    }

    int pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return INT16_MIN;
        }
        nextindex--;
        return data[nextindex];
    }

    //peek funtion
    int top(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return INT16_MIN;
        }
        return data[nextindex-1];

    }

};