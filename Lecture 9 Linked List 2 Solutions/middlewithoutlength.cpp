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

int middle(node* head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}


int main(){
    node *head=takeinputbetter();
    int num=middle(head);
    cout<<num<<endl;
}