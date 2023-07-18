#include<bits/stdc++.h>
using namespace std;
#include"node.cpp"

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
            
        }
        cin>>data;
    }
    return head;
}

void print(node *head){
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int findlength(node* head){
    int x=0;
    node* temp=head;
    while(temp!=nullptr){
        x++;
        temp=temp->next;
    }
    return x;
}

node* reverse(node*head){
    node *temp=head;
    node* pichla=nullptr;
    while(temp!=nullptr){
        node* agla=temp->next;
        temp->next=pichla;
        pichla=temp;
        temp=agla;
    }
    head=pichla;
    return head;
}

int main(){
    node*head=takeinputbetter();
    head=reverse(head);
    print(head);
}
