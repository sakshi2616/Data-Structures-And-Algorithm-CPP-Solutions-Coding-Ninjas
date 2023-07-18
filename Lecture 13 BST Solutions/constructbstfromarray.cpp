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

binarytreenode<int>* constructbst(int input[], int si, int ei){
    if(si>ei){
        return nullptr;
    }
    int mid=(si+ei)/2;
    binarytreenode<int>* root=new binarytreenode<int>(input[mid]);
    
    binarytreenode<int>* lefto=constructbst(input,si, mid-1);
    binarytreenode<int>* righto=constructbst(input, mid+1,ei);
    
    root->left=lefto;
    root->right=righto;
    return root;
}

void preorder(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
    
    cout<<root->data<<" ";

    preorder(root->left);
    
    preorder(root->right);

}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    binarytreenode<int>* root=constructbst(input, 0,n-1);
    preorder(root);
    
    
}