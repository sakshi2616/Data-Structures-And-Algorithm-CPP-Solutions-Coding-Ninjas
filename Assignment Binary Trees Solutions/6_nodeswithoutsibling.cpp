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

void nodesnosibling(binarytreenode<int>* front){
    vector<int> output;
    if(front==nullptr){
        return;
    }
    
    if(front->left!=nullptr && front->right==nullptr){
        cout<<front->left->data<<" ";
        
    }
    if(front->right!=nullptr && front->left==nullptr){
        cout<<front->right->data<<" ";
        
    }
    
    nodesnosibling(front->left);
    nodesnosibling(front->right);
    
}

int main(){
    binarytreenode<int>* root=takeinputlevelwise();
    nodesnosibling(root);

}