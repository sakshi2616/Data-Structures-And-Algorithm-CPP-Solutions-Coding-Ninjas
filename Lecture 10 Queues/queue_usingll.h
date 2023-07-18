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

template<typename T>
class queueusingll{
    node<T> *head;
    node<T> *tail;
    int size;

    public:

    queueusingll(){
        head=nullptr;
        tail=nullptr;
        size=0;
    }

    int getsize(){
        return size;
    }

    bool isempty(){
        return size==0;
    }

    void enqueue(T element){
        node<T> *newnode=new node<T>(element);

        if(head==nullptr && tail==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        size++;
    }

    T front(){
        if(isempty()){
            return 0;
        }
        return head->data;
    }

    T dequeue(){
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
};