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

node* middle(node* head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* mergesort(node* head){
    if(head->next==nullptr || head==nullptr){
        return head;
    }
    node* mid=middle(head);
    node* head2=mid->next;
    mid->next=nullptr;
    head=mergesort(head);
    head2=mergesort(head2);
    node* h=merge(head, head2);
    return h;
    
}


int main(){
    node*head=takeinputbetter();
    node* newhead=mergesort(head);
    print(newhead);
    
}