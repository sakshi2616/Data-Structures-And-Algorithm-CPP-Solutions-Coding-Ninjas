#include<bits/stdc++.h>
using namespace std;


//we will use dynamic arrays here, no fixed size needed
class stackusingarray{
    int *data;
    int nextindex;
    int capacity;

    public:

    stackusingarray(){
        data=new int[4];
        nextindex=0;
        capacity=4;
    } 
    

    int size(){
        return nextindex;
    }

    bool isempty(){
        return nextindex==0; //0==0 true else false
    }

    void push(int element){
        if(nextindex==capacity){
            //cout<<"stack is full "<<endl;
            //return;
            int* newdata=new int[capacity*2];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            data=newdata;
            
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