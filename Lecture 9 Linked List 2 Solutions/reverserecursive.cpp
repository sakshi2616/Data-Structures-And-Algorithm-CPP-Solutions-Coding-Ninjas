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

node* reverserec(node*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node *smallanswer=reverserec(head->next);
    node*temp=smallanswer;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head;
    head->next=nullptr;
    return smallanswer;
} //time complexity is 0(n2)

//iski time complexity kam krne ke lie tail maintain kr skte
//function ko head aur tail dono wapis krne chahiye
//but ek fn do values nahi return kr skta
//so we will use oopsss
// ek class bnayenge jismei 2 pointers ho(head and tail for us)
//and us class ka object return krwadenge

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

}//this has time complexity o(n)
//but do we actually need tail? no
//1 2 3 4 ki ll mei 4 3 2 wapis aya to 2 ka address already 
//hai 1 ke paas, tail ya traverse krke 2 tak jane ki zaroorat hi nahi

node* reverserecoptimsed(node*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node *smallanswer=reverserecoptimsed(head->next);
    node *tail=head->next;
    tail->next=head;
    head->next=nullptr;
    return smallanswer;
}

int main(){

    node*head=takeinputbetter();
    //head=reverserec(head);
    //print(head);

    //head=reverserec_better(head).head;
    //print(head);

    head=reverserecoptimsed(head);
    print(head);

}
