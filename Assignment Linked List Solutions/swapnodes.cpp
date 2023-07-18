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

node* swap(node* head, int m, int n){

    if(m==0){

        if(n==1){
            node*temp=head;
            node* a=head->next;
            node*b=head->next->next;

            head=a;
            a->next=temp;
            temp->next=b;
            return head;
        }

        else{
        node* temp=head;
        int count2=0;
        node* temp2=head;
        while(count2!=n-1){
            temp2=temp2->next;
            count2++;
        }
        
        node*c=temp2->next->next;//5-6-7

        //temp->next=temp2->next;
        head=temp2->next;
        head->next=temp->next;
        temp2->next=temp;
        temp->next=c;
        return head;
        }

    }


    else{
    node* temp1=head;
    int count=0;
    while(count!=m-1){
        temp1=temp1->next;
        count++;
    }
    int count2=0;
    node* temp2=head;
    while(count2!=n-1){
        temp2=temp2->next;
        count2++;
    }

    node *a=temp1->next; //5 ka adress
    node *b=temp2->next; //6 ka address
    //4-> temp
    //temp2->2
    node*c=temp2->next->next; //1-9-null ka address

    temp1->next=temp2->next;
    b->next=temp2;
    temp2->next=a;
    a->next=c;
    return head;
    }
}


int main(){
    node*head=takeinputbetter();
    int m,n;
    cin>>m>>n;
    //assuming m<n always
    
    head=swap(head,m,n);
    print(head);
}