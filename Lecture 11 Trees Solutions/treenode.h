#include<bits/stdc++.h>
using namespace std;

template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> children;

    treenode(T data){
        this->data=data;
    }
    //destructor
    ~treenode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};
