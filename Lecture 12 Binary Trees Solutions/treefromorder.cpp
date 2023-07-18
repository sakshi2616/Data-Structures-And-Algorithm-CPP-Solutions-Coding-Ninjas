#include<bits/stdc++.h>
using namespace std;
#include"binarytreenode.h"
#include<queue>


void printtreebetter(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<endl;
    queue<binarytreenode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        binarytreenode<int>* front=q.front();
        
        q.pop();
        if(front->left!=nullptr){
            q.push(front->left);
            cout<<front->left->data<<" ";
        }
        if(front->right!=nullptr){
            q.push(front->right);
            cout<<front->right->data;
        }
        cout<<endl;
    }
}

binarytreenode<int>* constructtreefromprein(int n, int preorder[], int inorder[], int ins, int ine, int prs, int pre){
    if(ins>ine){
        return NULL;
    }
    int rootdata=preorder[prs];
    binarytreenode<int>* root=new binarytreenode<int>(rootdata);
    int rootin=-1;
    for(int i=ins;i<=ine;i++){
        if(inorder[i]==rootdata){
            rootin=i;
            break;
        }
    }
    binarytreenode<int>* l=constructtreefromprein(n,preorder,inorder,ins,rootin-1,prs+1,rootin-ins+prs);
    binarytreenode<int>* r=constructtreefromprein(n,preorder,inorder,rootin+1,ine,rootin-ins+prs+1,pre);
    root->left=l;
    root->right=r;
    return root;
}


binarytreenode<int>* constructtreefrompostin(int n, int postorder[], int inorder[], int ins, int ine, int posts, int poste){
    if(posts>poste || ins>ine){
        return NULL;
    }
    int rootdata=postorder[poste];
    binarytreenode<int>* root=new binarytreenode<int>(rootdata);
    int rootin=-1;
    for(int i=ins;i<=ine;i++){
        if(inorder[i]==rootdata){
            rootin=i;
            break;
        }
    }
    binarytreenode<int>* l=constructtreefrompostin(n,postorder,inorder,ins,rootin-1,posts,poste-ine+rootin-1);
    binarytreenode<int>* r=constructtreefrompostin(n,postorder,inorder,rootin+1,ine,poste-ine+rootin,poste-1);
    root->left=l;
    root->right=r;
    return root;
}


int main(){
    int n;
    cin>>n;
    int postorder[n];
    int inorder[n];
    for(int i=0;i<n;i++){
        cin>>postorder[i];
    }

    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }

    binarytreenode<int>* root=constructtreefrompostin(n, postorder, inorder,0,n-1,0,n-1);
    
    printtreebetter(root);
}