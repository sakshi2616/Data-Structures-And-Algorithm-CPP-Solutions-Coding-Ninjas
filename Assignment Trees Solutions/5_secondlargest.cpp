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

class pairs{
    public:
    int l;
    int sl;

    pairs(int a,int b){
        l=a;
        sl=b;
    }
};

pairs secondlargest(treenode<int>* root){
    pairs answer(root->data,0);
    for(int i=0;i<root->children.size();i++){
        pairs smallans=secondlargest(root->children[i]);
        if(answer.l>smallans.l){
            answer.sl=smallans.l;
            //answer.l=root->data;
        }
        else if(answer.l<smallans.l && answer.l>smallans.sl){
            
            answer.sl=answer.l;
            answer.l=smallans.l;
        }
        else{
            answer.l=smallans.l;
            answer.sl=smallans.sl;
        }

    }
    return answer;

}


int main(){
    treenode<int>*root=takeinputlevelwise();

    pairs a=secondlargest(root);
    cout<<a.sl<<endl;
    
}
