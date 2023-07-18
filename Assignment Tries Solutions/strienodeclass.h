#include<bits/stdc++.h>
using namespace std;

class suffixtrieNode{
    public:
    char data;
    suffixtrieNode **children;
   
    suffixtrieNode(char data){
        this->data=data;
        children=new suffixtrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        
    }

};