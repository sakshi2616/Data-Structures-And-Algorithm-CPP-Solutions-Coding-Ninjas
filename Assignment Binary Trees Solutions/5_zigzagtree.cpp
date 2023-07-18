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

void printtreebetter(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
    queue<binarytreenode<int>*> q;
    q.push(root);
    q.push(nullptr);
    int c=1;
    while(q.size()!=0){
        if(q.front()!=nullptr){
        binarytreenode<int>* front=q.front();
        
        q.pop();
        cout<<front->data<<" ";
        if(c%2==0){
        if(front->left!=nullptr){
            q.push(front->left);
        }
        if(front->right!=nullptr){
            q.push(front->right);
        }
        }
        else{
        if(front->right!=nullptr){
            q.push(front->right);
        }
        if(front->left!=nullptr){
            q.push(front->left);
        }    
        }
        
        }
        else{
            q.pop();

            cout<<endl;
            if(q.size()!=0){
            q.push(nullptr);
            }
        }
        c++;
    }
}

int main(){
    binarytreenode<int>* root=takeinputlevelwise();
    printtreebetter(root);

}