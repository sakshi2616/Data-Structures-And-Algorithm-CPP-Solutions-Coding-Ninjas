#include<bits/stdc++.h>
using namespace std;

template<typename T>
class binarytreenode{
    public:

    T data;
    binarytreenode* left;
    binarytreenode* right;

    binarytreenode(T data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }

    ~binarytreenode(){
        delete left;
        delete right;
    }
};