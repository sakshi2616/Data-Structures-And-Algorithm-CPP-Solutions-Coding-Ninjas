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
    /*int a=height(root->left);
    int b=height(root->right);

    if(a!=0 || b!=0){
        if(a>=b){
            s=s+a;
        }
        else{
            s=s+b;
        }
    }
    return s;*/
    return 1+max(height(root->left), height(root->right));
}
//height fn ki time complexity is O(n)


int diameter(binarytreenode<int>* root){
    if(root==nullptr){
        return 0;
    }
    int option1=height(root->left)+height(root->right); 
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1, max(option2, option3));
} //O(n2) worst case
// time complexity-> n*height

//we will look at a better soln for diamter jismei woh bole ek node ko ki height aur dia sath mei le ao
//use inbuild pair class

pair<int, int> heightdiamter(binarytreenode<int>* root){
    if(root==nullptr){
        pair<int, int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int, int> leftans=heightdiamter(root->left);
    pair<int,int> rightans=heightdiamter(root->right);
    int ld=leftans.second;
    int lh=leftans.first;
    int rd=rightans.second;
    int rh=rightans.first;

    int height=1+max(lh,rh);
    int diamter=max(lh+rh, max(ld,rd));
    pair<int,int> p;
    p.first=height;
    p.second=diamter;
    return p;
}

int main(){
    
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    binarytreenode<int>* root=takeinputlevelwise();
    pair<int,int> p=heightdiamter(root);
    cout<<"height: "<<p.first<<endl;
    cout<<"diamter: "<<p.second;
    
}