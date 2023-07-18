#include<bits/stdc++.h>
using namespace std;
#include"binarytreenode.h"
#include<queue>

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

void elementsbtw(binarytreenode<int>* root,int s,int t){
    if(root==nullptr){
        return;
    }
    if(root->data>t){
        elementsbtw(root->left,s,t);
    }
    if(root->data<s){
        elementsbtw(root->right,s,t);
    }
    else{
        elementsbtw(root->left,s,t);
        cout<<root->data<<" ";
        elementsbtw(root->right,s,t);
    }
}

int main(){
    binarytreenode<int>* root=takeinputlevelwise();
    int s,t;
    cin>>s>>t;
    elementsbtw(root,s,t);
    
}