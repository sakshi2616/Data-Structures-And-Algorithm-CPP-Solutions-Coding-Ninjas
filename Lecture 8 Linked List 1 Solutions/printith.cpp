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

int findlength(node* head){
    int x=0;
    node* temp=head;
    while(temp!=nullptr){
        x++;
        temp=temp->next;
    }
    return x;
}

int printat(node*head, int x){
    int y=0;
    node* temp=head;
    while(y!=x){
        temp=temp->next;
        y++;
    }
    return temp->data;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        node* head=takeinputbetter();
        int x;
        cin>>x;
        int number=printat(head, x);
        cout<<number<<endl;
    }
}