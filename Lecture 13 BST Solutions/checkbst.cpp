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

int maximum(binarytreenode<int>* root){
    if(root==nullptr){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));

}

int minimum(binarytreenode<int>* root){
    if(root==nullptr){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));

}

bool checkbst(binarytreenode<int>* root){
    if(root==nullptr){
        return true;
    }
    int leftmax=maximum(root->left);
    int rightmin=minimum(root->right);
    
    bool output= (root->data > leftmax) && (root->data <rightmin) && checkbst(root->left) && checkbst(root->right);
    return output;
} //O(nh) (n*height) like n2

//better method

class isbstreturn{
    public: 
    bool isbst;
    int minimum;
    int maximum;
};

isbstreturn isbst(binarytreenode<int>* root){
    if(root==nullptr){
        isbstreturn output;
        output.isbst=true;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        return output;
    }
    isbstreturn lefto=isbst(root->left);
    isbstreturn righto=isbst(root->right);
    int minimum=min(root->data, min(lefto.minimum, righto.minimum));
    int maximum=max(root->data, max(lefto.maximum, righto.maximum));
    bool isbstfinal=(root->data>lefto.maximum) && (root->data<=righto.minimum) && lefto.isbst && righto.isbst;
    isbstreturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isbst=isbstfinal;
    return output;
}

//another solution using constraints

bool isbst3(binarytreenode<int>* root, int min=INT_MIN, int max=INT_MAX){
    if(root==nullptr){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }
    bool isleftok=isbst3(root->left, min, root->data-1);
    bool isrightok=isbst3(root->right,root->data,max);
    return isleftok && isrightok;

}


int main(){
    binarytreenode<int>* root=takeinputlevelwise();
    cout<<isbst3(root);
    delete root;
    
}