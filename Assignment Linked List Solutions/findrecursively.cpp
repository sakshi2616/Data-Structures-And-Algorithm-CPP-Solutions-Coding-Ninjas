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

int find(node*head, int num){
    
    if(head==nullptr){
        return -1;
    }

    if(head->data==num){
        return 0;
    }
    
    int a=find(head->next, num);
    if(a!=-1){
        return 1+a;
    }
    else{
        return -1;
    }
}

int main(){
    node*head=takeinputbetter();
    int num;
    cin>>num;
    int t=find(head, num);
    cout<<t<<endl;
}