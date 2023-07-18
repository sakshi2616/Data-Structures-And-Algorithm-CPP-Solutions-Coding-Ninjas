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


int height(binarytreenode<int>* root){
    int s=1;
    if(root==nullptr){
        return 0;
    }
    int a=height(root->left);
    int b=height(root->right);
    int c=max(a,b);
    return s+c;
}



pair<bool,int> balanced(binarytreenode<int>* root){
    if(root==nullptr){
        pair<bool,int> ans;
        ans.first=true;
        ans.second=0;
        return ans;
    }
    pair<bool, int> l=balanced(root->left);
    pair<bool,int> r=balanced(root->right);
    pair<bool, int> ans;
    ans.first=true;
    ans.second=max(l.second,r.second)+1;
    if(l.first==false || r.first==false){
        ans.first=false;
    }
    else if(l.second-r.second>1 || r.second-l.second>1){
        ans.first=false;
    }
    return ans;

}

int main(){
    binarytreenode<int>* root=takeinputlevelwise();
    pair<bool,int> ans=balanced(root);
    cout<<ans.first<<endl;

}