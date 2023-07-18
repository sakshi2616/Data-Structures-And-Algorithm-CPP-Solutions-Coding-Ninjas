#include<bits/stdc++.h>
using namespace std;
#include"binarytreenode.h"
#include<queue>

void printtree(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }

    cout<<root->data<<":";
    if(root->left!=nullptr){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=nullptr){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}

binarytreenode<int>* takeinput(){
    //if -1 data->null return
    int rootdata;
    cout<<"enter data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return nullptr;
    }
    binarytreenode<int>* root=new binarytreenode<int>(rootdata);
    binarytreenode<int>* leftchild=takeinput();
    binarytreenode<int>* rightchild=takeinput();
    root->left=leftchild;
    root->right=rightchild;
}

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

void printtreelevelwise(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
   
    queue<binarytreenode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        binarytreenode<int>* front=q.front();
        cout<<front->data<<":";
        q.pop();
        if(front->left!=nullptr){
            q.push(front->left);
            cout<<"L"<<front->left->data;
        }
        if(front->right!=nullptr){
            q.push(front->right);
            cout<<"R"<<front->right->data;
        }
        cout<<endl;
    }
}

int numnodes(binarytreenode<int>* root){
    if(root==nullptr){
        return 0;
    }
    return 1+numnodes(root->left)+numnodes(root->right);
}

bool isnodepresent(binarytreenode<int>* root, int n){
    bool ans=false;

    if(root==nullptr){
        return ans;
    }
    if(root->data==n){
        ans=true;
    }
    bool smallans=isnodepresent(root->left, n);
    
    bool smallans2=isnodepresent(root->right, n);

    if(smallans==true){
        ans=smallans;
    }
    if(smallans2==true){
        ans=smallans2;
    }
    return ans;
    
}

int height(binarytreenode<int>* root){
    int s=1;
    if(root==nullptr){
        return 0;
    }
    int a=height(root->left);
    int b=height(root->right);

    if(a!=0 || b!=0){
        if(a>=b){
            s=s+a;
        }
        else{
            s=s+b;
        }
    }
    return s;
}

void mirror(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
    if(root->left!=nullptr && root->right!=nullptr){
        binarytreenode<int>* temp=root->right;
        root->right=root->left;
        root->left=temp;
    }
    mirror(root->left);
    mirror(root->right);
    
}

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

void inorder(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
    

    postorder(root->left);
    
    postorder(root->right);

    cout<<root->data<<" ";
}

void preorder(binarytreenode<int>* root){
    if(root==nullptr){
        return;
    }
    
    cout<<root->data<<" ";

    preorder(root->left);
    
    preorder(root->right);

}

int diameter(binarytreenode<int>* root){
    if(root==nullptr){
        return 0;
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1, max(option2, option3));
}

int main(){
    //binarytreenode<int>* root=new binarytreenode<int>(1);
    //binarytreenode<int>* node1=new binarytreenode<int>(2);
    //binarytreenode<int>* node2=new binarytreenode<int>(3);

    //root->left=node1;
    //root->right=node2;
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    binarytreenode<int>* root=takeinputlevelwise();
    //printtreelevelwise(root);
    /*int num;
    cout<<"enter number"<<endl;
    cin>>num;
    bool ans=isnodepresent(root,num);
    if(ans==true){
        cout<<"True"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }*/

    //int h=height(root);
    //cout<<"height is"<<" "<<h<<endl;

    //mirror(root);
    //printtreebetter(root);
    cout<<"inorder traversal is ";
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal is ";
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal is ";
    postorder(root);

}