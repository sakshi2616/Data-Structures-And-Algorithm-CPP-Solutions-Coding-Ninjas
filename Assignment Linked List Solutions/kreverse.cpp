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

class pairs{
    public:
    
    node* head;
    node*tail;

};

pairs reverserec_better(node*head){
    if(head==nullptr || head->next==nullptr){
        pairs ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    pairs smallanswer=reverserec_better(head->next);
    smallanswer.tail->next=head;
    head->next=nullptr;
    pairs ans;
    ans.head=smallanswer.head;
    ans.tail=head;
    return ans;

}

node* reversek(node* head, int k){
    int count=0;
    node* temp=head;
    while(temp!=nullptr){
    node* head1=temp;
    node* tail1=temp;
    if(temp==head){

    while(count!=k-1 && temp!=nullptr){
        temp=temp->next;
        tail1=tail1->next;
        count++;
    }
    count=0;
    temp=tail1->next;
    tail1->next=nullptr;
    pairs answer=reverserec_better(head1);
    head1=answer.head;
    tail1=answer.tail;
    tail1->next=temp;
    head=head1;
    }
    else{
    while(count!=k-1 && temp->next!=nullptr){
        temp=temp->next;
        tail1=tail1->next;
        count++;
    }
    if(temp->next==nullptr){
        count=0;
        pairs answer=reverserec_better(head1);
        head1=answer.head;
        tail1=answer.head;
        node*tempo=head;
        while(tempo->next!=tail1){
            tempo=tempo->next;
        }
        tempo->next=head1;
        return head;
    }
    else{
    count=0;
    temp=tail1->next;
    tail1->next=nullptr;
    pairs answer=reverserec_better(head1);
    head1=answer.head;
    tail1=answer.tail;
    tail1->next=temp;
    node*tempo=head;
    while(tempo->next!=tail1){
        tempo=tempo->next;
    }
    tempo->next=head1;
    }
    }
    }
    return head;

}

node* reverse(node* head, int k)
{
    // base case
    if (!head)
        return nullptr;
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
  
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
  
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
  
    /* prev is new head of the input list */
    return prev;
}

int main(){
    node*head=takeinputbetter();
    int k;
    cin>>k;
    head=reverse(head,k);
    print(head);
}