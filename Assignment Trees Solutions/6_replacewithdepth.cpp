#include<bits/stdc++.h>
using namespace std;

#include"treenode.h"
#include<queue>

treenode<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"ENTER ROOT DATA:"<<endl;
    cin>>rootdata;

    treenode<int> *root=new treenode<int>(rootdata);
    queue<treenode<int>*> pendingnodes;

    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        treenode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter the no of children of "<<front->data<<endl;

        int numchild;
        cin>>numchild;

        for(int i=0;i<numchild;i++){
            int childdata;
            cout<<"enter "<<i<<"th child of"<<front->data<<endl;
            cin>>childdata;

            treenode<int>*child=new treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }

    return root;

}

void printtreelevelwise(treenode<int> *root){
    if(root==nullptr){
        return;
    }
    queue<treenode<int>*> q;
    
    q.push(root);
    while(q.size()!=0){
        treenode<int>* front=q.front();
        q.pop();
        if(front==root){
            cout<<front->data<<endl;
        }
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<endl;
    }

}

treenode<int>* repwithd(treenode<int>* root, int a){
    root->data=a;
    for(int i=0;i<root->children.size();i++){
        repwithd(root->children[i],a+1);
    }

    return root;
    
}

int main(){
    treenode<int>*root=takeinputlevelwise();
    root=repwithd(root,0);
    printtreelevelwise(root);
}
