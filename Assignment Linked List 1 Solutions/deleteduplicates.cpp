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

node* deleteduplicates(node *head){
    node *temp=head;
    node*temp2=head->next;

    while(temp2!=nullptr){
        if(temp->data==temp2->data){
            if(temp==head){
                temp2=temp2->next;
                delete temp->next;
                temp->next=temp2;
                head=temp;

            }
            else{
                temp2=temp2->next;
                delete temp->next;
                temp->next=temp2;
            }
        }

        else{
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    return head;
}

int main(){
    node *head=takeinputbetter();
    head=deleteduplicates(head);
    print(head);
}