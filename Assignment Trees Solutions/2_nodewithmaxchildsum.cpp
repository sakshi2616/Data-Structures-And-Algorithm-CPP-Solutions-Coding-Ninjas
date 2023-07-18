
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

class pairs{
    public:

    int maxsumyet;
    treenode<int>* maxsumnode;
};

pairs maxchildsum(treenode<int>* root){
    
    int max=root->data;

    for(int i=0;i<root->children.size();i++){
        max+=root->children[i]->data;
    }
    pairs answer;
    answer.maxsumnode=root;
    answer.maxsumyet=max;

    for(int i=0;i<root->children.size();i++){
        pairs p1=maxchildsum(root->children[i]);
        if(p1.maxsumyet>max){
            answer.maxsumyet=p1.maxsumyet;
            answer.maxsumnode=p1.maxsumnode;
        }
    }

    return answer;
}

int main(){
    treenode<int>*root=takeinputlevelwise();
    pairs answer=maxchildsum(root);
    cout<<answer.maxsumnode->data<<endl;


}

