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

node* insertnode(node*head, int i, int data){
    node *newnode=new node(data);
    int count=0;
    node*temp=head;

    if(i==0){
        newnode->next=head;
        head=newnode;
        return head;
    }

    while(temp!=nullptr && count<i-1){
        temp=temp->next;
        count++; 
    }
    if(temp!=nullptr){
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}

node* deleteati(node *head, int i){
    node*temp=head;
    int count=0;
    if(i==0){
        node *t=head;
        head=head->next;
        delete t;
        return head;
    }

    while( temp!=nullptr && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=nullptr){
        node *a=temp->next;
        node *b=a->next;
        temp->next=b;
        delete a;
    }
    return head;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        node *head=takeinputbetter();
        int x;
        cin>>x;
        head=deleteati(head,x);
        print(head);
        cout<<endl;
    }

}