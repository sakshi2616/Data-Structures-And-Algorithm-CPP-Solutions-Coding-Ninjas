#include<bits/stdc++.h>
using namespace std;
#include"binarytreenode.h"
#include"node.cpp"
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

void print(node *head){
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

vector<node*> linkedtree(binarytreenode<int>* root){
    vector<node*> output;
    if(root==nullptr){
        output.push_back(nullptr);
        return output;
    }
    queue<binarytreenode<int>*> q;
    q.push(root);
    q.push(nullptr);
    node* head=nullptr;
    node* tail=nullptr;
    //vector<node*> output;
    while(q.size()!=0){
        if(q.front()!=nullptr){
            binarytreenode<int>* curr=q.front();
            q.pop();
            node* current=new node(curr->data);
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
            if(head==nullptr && tail==nullptr){
                head=current;
                tail=current;
            }
            else if(head!=nullptr){
                tail->next=current;
                tail=tail->next;
            }
        }
        else if(q.front()==nullptr){
            output.push_back(head);
            head=nullptr;
            tail=nullptr;
            q.pop();
            if(q.size()!=0){
                q.push(nullptr);
            }
        }
    }
}

int main(){
    binarytreenode<int>* root=takeinputlevelwise();
    vector<node*> output=linkedtree(root);
    for(int i=0;i<output.size();i++){
        print(output[i]);
        cout<<endl;
    }

}

