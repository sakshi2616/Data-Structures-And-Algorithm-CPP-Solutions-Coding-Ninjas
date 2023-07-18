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
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<endl;
    }

}

int height(treenode<int>* root){
    int a=0;

    treenode<int>*curr=root;
    for(int i=0;i<root->children.size();i++){
        int b=height(root->children[i]);
        if(b>a){
            a=b;
        }
    }
    return 1+a;
}

void deletetree(treenode<int>* root){
    for(int i=0;i<root->children.size();i++){
        deletetree(root->children[i]);
    }
    delete root;
}

bool hasx(treenode<int>* root, int x){
    bool answer=false;
    if(root->data==x){
        return true;
    }
    
    for(int i=0;i<root->children.size();i++){
        answer=hasx(root->children[i],x);
    }
    return answer;
}

int main(){
    treenode<int>*root=takeinputlevelwise();

    int x;
    cin>>x;
    bool answer=hasx(root,x);
    if(answer){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
}
