#include<bits/stdc++.h>
using namespace std;

template <typename T>
//we will use dynamic arrays here, no fixed size needed
class stackusingarray{
    T *data;
    int nextindex;
    int capacity;

    public:

    stackusingarray(){
        data=new T[4];
        nextindex=0;
        capacity=4;
    } 
    

    int size(){
        return nextindex;
    }

    bool isempty(){
        return nextindex==0; //0==0 true else false
    }

    void push(T element){
        if(nextindex==capacity){
            //cout<<"stack is full "<<endl;
            //return;
            T* newdata=new T[capacity*2];
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

    T pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        nextindex--;
        return data[nextindex];
    }

    //peek funtion
    T top(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[nextindex-1];

    }

};