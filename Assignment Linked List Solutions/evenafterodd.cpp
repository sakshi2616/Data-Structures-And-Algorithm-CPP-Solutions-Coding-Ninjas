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

node* oddeven(node* head){
    node*oddhead=nullptr;
    node*oddtail=nullptr;
    node*evenhead=nullptr;
    node*eventail=nullptr;

    node*temp=head;
    while(temp!=nullptr){

        if(temp->data%2==0){
            if(evenhead==nullptr){
                evenhead=temp;
                eventail=temp;
            }
            else{
                eventail->next=temp;
                eventail=temp;
            }
        }
        else{
            if(oddhead==nullptr){
                oddhead=temp;
                oddtail=temp;
            }
            else{
                oddtail->next=temp;
                oddtail=temp;
            }
        }
        temp=temp->next;
    }

    if(oddhead==nullptr || evenhead==nullptr){
        return head;
    }

    oddtail->next=evenhead;
    eventail->next=nullptr;
    return oddhead;
}

int main(){
    node*head=takeinputbetter();
    head=oddeven(head);
    print(head);
}