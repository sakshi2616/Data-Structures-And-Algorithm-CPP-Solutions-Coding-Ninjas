#include<bits/stdc++.h>
using namespace std;
#include"binarytreenode.h"
#include<queue>
#include"node.h"


binarytreenode<int>* takeinputlevelwise(){
    //use queue
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return nullptr;
    }
    binarytreenode<int>* root=new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*> pendingnodes;

    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        binarytreenode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child of"<<front->data<<endl;
        int leftchildata;
        cin>>leftchildata;
        if(leftchildata!=-1){
            binarytreenode<int>* child=new binarytreenode<int>(leftchildata);
            front->left=child;
            pendingnodes.push(child);
        }
        cout<<"enter right child of"<<front->data<<endl;
        int rightchildata;
        cin>>rightchildata;
        if(rightchildata!=-1){
            binarytreenode<int>* child=new binarytreenode<int>(rightchildata);
            front->right=child;
            pendingnodes.push(child);
        }
    }

    return root;

}

void printtreelevelwise(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
   
    queue<binarytreenode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        binarytreenode<int>* front=q.front();
        cout<<front->data<<":";
        q.pop();
        if(front->left!=nullptr){
            q.push(front->left);
            cout<<"L"<<front->left->data;
        }
        if(front->right!=nullptr){
            q.push(front->right);
            cout<<"R"<<front->right->data;
        }
        cout<<endl;
    }
}

class llfrombstdt{
    public:
    node* head;
    node* tail;
};

llfrombstdt llfrombst(binarytreenode<int>* root){
    if(root==nullptr){
        llfrombstdt output;
        output.head=nullptr;
        output.tail=nullptr;
        return output;
    }
    node* curr=new node(root->data);
    llfrombstdt lefto=llfrombst(root->left);
    llfrombstdt righto=llfrombst(root->right);
    node* head=curr;
    node* tail=curr;
    if(lefto.tail!=nullptr){
    lefto.tail->next=curr;
    head=lefto.head;
    }
    if(righto.head!=nullptr){
    curr->next=righto.head;
    tail=righto.tail;
    }
    llfrombstdt output;
    output.head=head;
    output.tail=tail;
    return output;


}

void print(node *head){
    node *temp=head;
    while(temp!=nullptr){

        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}


int main(){
    binarytreenode<int>* root=takeinputlevelwise();
    llfrombstdt ans=llfrombst(root);
    print(ans.head);
}