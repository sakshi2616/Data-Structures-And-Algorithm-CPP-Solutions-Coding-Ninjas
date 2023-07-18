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

node* deleter(node *head, int i){
    if(i==1){
        
        node *a=head->next;
        node *b=a->next;
        head->next=b;
        delete a;
        return head;
    }

    else if(i==0){
        node* temp=head;
        head=temp->next;
        delete temp;
        return head;
    }

    else{
        deleter(head->next, i-1);
    }
}

void print(node *head){
    node *temp=head;
    
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    node *head=takeinputbetter();
    int i;
    cin>>i;
    node *s=deleter(head, i);
    if(i==0){
        print(s);
    }
    else{
        int count=0;
        node *temp=head;
        while(count!=i-2){
            temp=temp->next;
            count++;
        }
        temp->next=s;
        print(head);
    }

}