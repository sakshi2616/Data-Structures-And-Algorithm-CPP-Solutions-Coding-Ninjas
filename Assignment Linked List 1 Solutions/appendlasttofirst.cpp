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

node* append(node*head, int num){
    int length=findlength(head);
    int togo=length-num-1;
    int count=0;
    node* temp=head;
    while(count!=togo){
        temp=temp->next;
        count++;
    }
    node* hold=temp->next;
    temp->next=nullptr;
    int t=0;
    node*temp2=hold;
    while(t!=num-1){
        temp2=temp2->next;
        t++;
    }
    temp2->next=head;
    head=hold;
}

int main(){
    node *head=takeinputbetter();
    int num;
    cin>>num;
    int length=findlength(head);
    node* newhead=append(head,num);
    print(newhead);
}