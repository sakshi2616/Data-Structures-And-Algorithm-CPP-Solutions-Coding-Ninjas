#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node{
    public:
    T data;
    node<T> *next;

    node(T data){
        this->data=data;
        next=nullptr;
    }
};
template <typename T>
class stackusingll{
    node<T>*head;
    int size; //no of elements in stack

    public:
    stackusingll(){
        head=nullptr;
        size=0;
    }

    int getsize(){
        return size;
    }

    bool isempty(){
        return size==0;
    }

    void push(T element){
        node<T> *newnode=new node<T>(element);

        if(head==nullptr){
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
        size++;
    }


    T pop(){
        if(isempty()){
            return 0;
        }
        else{
        T answer=head->data;
        node<T> *temp=head;
        head=head->next;
        delete temp;
        size--;
        return answer;
        }
    }

    T top(){
        if(isempty()){
            return 0;
        }
        else{
        return head->data;
        }
    }

    

};