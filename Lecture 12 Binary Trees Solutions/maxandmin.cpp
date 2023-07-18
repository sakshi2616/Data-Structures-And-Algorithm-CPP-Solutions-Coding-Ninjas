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

pair<int,int> maxmin(binarytreenode<int>* root){
    if(root==nullptr){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> curr;
    pair<int,int> leftans=maxmin(root->left);
    pair<int,int> rightans=maxmin(root->right);

    int maxrn=max(root->data, max(leftans.second,rightans.second));
    curr.second=maxrn;
    if(leftans.first==0 && rightans.first==0){
        curr.first=root->data;
    }
    else if(leftans.first==0){
        int minrn=min(root->data,rightans.first);
        curr.first=minrn;
    }
    else if(rightans.first==0){
        int minrn=min(root->data,leftans.first);
        curr.first=minrn;
    }
    else{
        int minrn=min(root->data, min(leftans.first, rightans.first));
        curr.first=minrn;
    }
    
    return curr;
}



int main(){
    
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    binarytreenode<int>* root=takeinputlevelwise();
    pair<int,int> ans=maxmin(root);
    cout<<ans.first<<" "<<ans.second<<endl;
}