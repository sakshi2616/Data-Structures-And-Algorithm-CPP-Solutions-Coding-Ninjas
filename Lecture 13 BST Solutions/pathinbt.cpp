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

vector<int>* getroottonodepath(binarytreenode<int>*root, int data){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==data){
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* lefto=getroottonodepath(root->left,data);
    if(lefto!=nullptr){
        lefto->push_back(root->data);
        return lefto;
    }
    vector<int>* righto=getroottonodepath(root->right,data);
    if(righto!=nullptr){
        righto->push_back(root->data);
        return righto;
    }
    else{
        return nullptr;
    }
}

int main(){
    binarytreenode<int>* root=takeinputlevelwise();
    vector<int>* output=getroottonodepath(root,8);
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<" ";
    }
    delete output;
}   
//bt not bst
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1