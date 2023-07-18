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

int lengthr(node *head){
    if (head == NULL) {
        return 0;
    }
    else {
        return 1 + lengthr(head->next);
    }

}

int main(){
    node *head=takeinputbetter();
    int length=lengthr(head);
    cout<<length<<endl;
}