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

node* reverse(node*head){
    node *temp=head;
    node* pichla=nullptr;
    while(temp!=nullptr){
        node* agla=temp->next;
        temp->next=pichla;
        pichla=temp;
        temp=agla;
    }
    head=pichla;
    return head;
}

bool palindrome(node* head, int l){
    bool answer=true;
    int mid;
    if(l%2==0){
        mid=(l/2)-1;
    }
    else{
        mid=l/2;
    }
    node* temp=head;
    int count=0;
    while(count!=mid){
        temp=temp->next;
        count++;
    }

    node*head2=temp->next;
    temp->next=nullptr;
    head2=reverse(head2);
    node*tempa=head;
    node* tempb=head2;
    while(tempa!=nullptr && tempb!=nullptr){
        if(tempa->data!=tempb->data){
            answer=false;
            break;
        }
        tempa=tempa->next;
        tempb=tempb->next;
    }

    return answer;
}


int main(){
    node *head=takeinputbetter();
    int length=findlength(head);
    if(length==0){
        cout<<"True"<<endl;
    }
    else{
    bool answer=palindrome(head,length);

    if(answer==0){
        cout<<"False"<<endl;
    }
    else{
        cout<<"True"<<endl;
    }
    }

}