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

treenode<int>* takeinput(){
    //taking input(dfs) recursively
    int rootdata;
    cout<<"ENTER DATA:"<<endl;
    cin>>rootdata;
    
    treenode<int> *root=new treenode<int>(rootdata);

    int n;
    cout<<"enter no of children of "<<rootdata<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        treenode<int>* childnode=takeinput();
        root->children.push_back(childnode);
    }
    return root;

}

void printtree(treenode<int> *root){
    //not base case, but edge case
    if(root==nullptr){
        return;
    }

    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printtree(root->children[i]);
    }
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

int sumallnodes(treenode<int>* root){
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=sumallnodes(root->children[i]);
    }
    return ans;
}

treenode<int>* largest(treenode<int>* root){
    if(root==nullptr){
        return NULL;
    }
    treenode<int>*curr=root;
    
    for(int i=0;i<root->children.size();i++){
        treenode<int>* dec=largest(root->children[i]);
        if(curr->data<dec->data){
            curr=dec;
        }
    }
    return curr;
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

void printatlevelk(treenode<int>* root, int k){

    if(root==nullptr){
        return;
    }

    if(k==0){
        cout<<root->data<<endl;
        return;
    }

    for(int i=0;i<root->children.size();i++){
        printatlevelk(root->children[i], k-1);
    }
}

//find no of leaf nodes
int leaf(treenode<int>* root){
    int l=0;
    if(root->children.size()==0){
        return 1;
    }
    for(int i=0;i<root->children.size();i++){
        l+=leaf(root->children[i]);
    }
    return l;
}

//pre-order traversal
void preorder(treenode<int>*root){
    if(root==nullptr){
        return;
    }

    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

//post-order traversal
void postorder(treenode<int>*root){
    if(root==nullptr){
        return;
    }

    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
     cout<<root->data<<" ";
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
    /*treenode<int> *root=new treenode<int>(1);
    treenode<int> *node1=new treenode<int>(2);
    treenode<int> *node2=new treenode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    */


    //treenode<int>*root=takeinput();

    treenode<int>*root=takeinputlevelwise();
    //printtreelevelwise(root);
    //int ans=countnodes(root);
    //cout<<ans<<endl;

    //int sum=sumallnodes(root);
    //cout<<sum<<endl;
    
    //treenode<int>* ans=largest(root);
    //cout<<ans->data<<endl;

    //int h=height(root);

    //int l=leaf(root);
    //cout<<l<<endl;
    //i/p: 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    //preorder(root);
    //cout<<endl;
    //postorder(root);

    //to-do : delete tree
    //deletetree(root); //method one making a function on our own

    //method 2:destructor (delete root; likhne se hi full tree delete hojaye)
    //delete root;
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
