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

int find(node *head, int num){
    int count=0;
    node* temp=head;
    while(temp!=nullptr){
        if(temp->data==num){
            return count;
        }
        else{
            count++;
            temp=temp->next;
        }
    }
    if(temp==nullptr){
        return -1;
    }
}

int main(){
    node *head=takeinputbetter();
    int num;
    cin>>num;
    int index=find(head,num);
    cout<<index<<endl;
}