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
    if(head==nullptr){
        return;
    }
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void deletennodes(node*head, int M, int N){
    node *current = head, *temp;
   int count;
   while (current) {
      // skip M nodes
      for (count = 1; count < M && current!= NULL; count++) {
         current = current->next;
      }
      // end of the linked list
      if (current == NULL) {
         return;
      }
      // deleting N nodes after M nodes
      temp = current->next;
      for (count = 1; count <= N && temp != NULL; count++) {
         node *deletingNode = temp;
         temp = temp->next;
         free(deletingNode);
      }
      current->next = temp;
      current = temp;
   }
}

int main(){
    node*head=takeinputbetter();
    int m,n;
    cin>>m;
    cin>>n;
    if(m==0){
        print(nullptr);
    }
    else{
        deletennodes(head, m ,n);
        print(head);
    }
}