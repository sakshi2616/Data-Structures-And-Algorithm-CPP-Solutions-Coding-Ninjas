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

node* merge(node*head1, node*head2){
    node* head=nullptr;
    node* tail=nullptr;
    while(head1!=nullptr && head2!=nullptr){
    if(head==nullptr){
    if(head1->data<=head2->data){
        head=head1;
        tail=head1;
        head1=head1->next;
    }
    else{
        head=head2;
        tail=head2;
        head2=head2->next;
    }
    }
    else{
        if(head1->data<=head2->data){
            tail->next=head1;
            tail=head1;
            head1=head1->next;

        }
        else{
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }

    }
    }

    if(head1!=nullptr){
        tail->next=head1;
    }
    else{
        tail->next=head2;
    }
    return head;
}


int main(){
    node*head1=takeinputbetter();
    node* head2=takeinputbetter();
    node*head=merge(head1,head2);
    print(head);
}