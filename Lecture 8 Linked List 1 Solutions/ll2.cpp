#include<bits/stdc++.h>
using namespace std;
#include"node.cpp"


node* takeinput(){
    int data;
    cin>>data;
    node *head=nullptr;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==nullptr){
            head=newnode;
        }
        else{
            node *temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        cin>>data;
    }
    return head;
} //this fn has n2 time complexity but we can reduce this by making a tail ptr

node* takeinputbetter(){
    int data;
    cin>>data;
    node *head=nullptr;
    node *tail=nullptr;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            
            tail=tail->next;
            //or
            //tail=newnode;
        }
        cin>>data;
    }
    return head;
}// time complexity reduces to o(n)


void print(node *head){
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    node n1(1);
    node *head=&n1;

    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;

    //printing this linkedlist

    print(head);


    //making getinput funtion
    node*head2=takeinput();
    print(head2);
}