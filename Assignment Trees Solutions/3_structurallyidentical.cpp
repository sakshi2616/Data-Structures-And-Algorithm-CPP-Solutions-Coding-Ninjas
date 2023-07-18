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

int countnodes(treenode<int>* root){

    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=countnodes(root->children[i]);
    }
    return ans;
}

bool isIdentical(treenode<int> *root1, treenode<int> * root2) {
    if(root1->data != root2->data)
        return false;
    
    if(root1->children.size() != root2->children.size())
        return false;
    
    bool ans =true;
    for(int i=0;i<root1->children.size();i++)
    {
        bool smallans = isIdentical(root1->children[i],root2->children[i]);
        if(smallans == false)
        {  
            ans=smallans;
            return ans;
        }
    }
    return ans;

}

int main(){

    treenode<int>*root1=takeinputlevelwise();
    treenode<int>*root2=takeinputlevelwise();
    bool answer=isIdentical(root1,root2);
    if(answer){
        cout<<"True"<<endl;
    }    
    else{
        cout<<"false"<<endl;
    }
}
