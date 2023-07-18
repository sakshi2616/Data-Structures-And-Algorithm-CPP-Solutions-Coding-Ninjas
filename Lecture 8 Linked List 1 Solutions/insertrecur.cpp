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

node * insertr(node *head, int i, int data){
    if(i==0){
        node *newnode=new node(data);
        node *temp=head;
        newnode->next=head;
        head=newnode;
        return head;
    }

    else{
        insertr(head->next, i-1, data);
    }
}

int main(){
    node*head=takeinputbetter();
    int i;
    cin>>i;
    int x;
    cin>>x;
    node *s=insertr(head, i, x);
    if(i==0){
        print(s);
    }
    else{
        int count=-1;
        node *temp=head;
        while(count!=i-2){
            temp=temp->next;
            count++;
        }
        temp->next=s;
        print(head);
    }

}