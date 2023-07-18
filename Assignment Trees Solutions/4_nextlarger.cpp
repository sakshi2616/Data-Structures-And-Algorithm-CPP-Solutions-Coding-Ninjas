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

class pairs{

    public:
    int diff;
    treenode<int>* leastdiffnode;

    pairs(int d, treenode<int>* l){
        diff=d;
        leastdiffnode=l;
    }
};

pairs nextlarger(treenode<int>*root, int n){
    int a=root->data;
    pairs answer(n,root);
    if(a<n){
        //int d=n;
        for(int i=0;i<root->children.size();i++){
            pairs smallans=nextlarger(root->children[i], n);
            if(smallans.diff<answer.diff){
                answer.leastdiffnode=smallans.leastdiffnode;
                answer.diff=smallans.diff;
            }
        }
    }
    else{
        int d=a-n;
        answer.diff=d;
        
        for(int i=0;i<root->children.size();i++){
            pairs smallans=nextlarger(root->children[i], n);
            if(smallans.diff<d ){
                answer.leastdiffnode=smallans.leastdiffnode;
                answer.diff=smallans.diff;
            }
        }

    }

    return answer;
}

int main(){
    int n;
    cin>>n;
    treenode<int>*root=takeinputlevelwise();
    pairs ans=nextlarger(root,n);
    cout<<ans.leastdiffnode->data<<endl;
}
