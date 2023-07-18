#include<bits/stdc++.h>
using namespace std;
#include "strienodeclass.h"

class Trie{
    suffixtrieNode *root;
    public:

    Trie(){
       root=new suffixtrieNode('\0');
    }

    void insertpls(suffixtrieNode* root, string help){

        if(help.size()==0){
            return;
        }

        suffixtrieNode*temp;
        int index=help[0]-'a';
        if(root->children[index]!=nullptr){
            temp=root->children[index];
        }
        else{
            temp=new suffixtrieNode(help[0]);
            root->children[index]=temp;
        }
        insertpls(temp,help.substr(1));
    }

    void insertword(suffixtrieNode* root,string word){
        //base case
        if(word.size()==0){
            return;
        }

        //small calculations
        string help=word;
        
        insertpls(root,help);
        
        
        //recursive call
        insertword(root,word.substr(1));

        
    }

    //for user
    void insertwordhelper(string word){
        insertword(root,word);
    }
    
    bool search(suffixtrieNode *root,string patt) {
        
        if(root->children[patt[0]-'a']==NULL)
            return false;

        if(patt.size()==1)
        {
            return root->children[patt[0]-'a']!=nullptr;
        }

        return search(root->children[patt[0]-'a'],patt.substr(1)); 
    }

    bool search(string word)
    {  return search(root,word);}


    /*
    void remove(TrieNode* root, string word){
        //base case
        if(word.size()==0){
            root->isterminal=false;
        }

        //small calculations
        TrieNode* child;
        int index=word[0]-'a';
        if(root->children[index]!=nullptr){
            child=root->children[index];
        }
        else{
            //word not found
            return;
        }

        //recursive call
        remove(child,word.substr(1));

        //check if child useless or not 
        if(child->isterminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=nullptr){
                    return;
                }

            }
            delete child;
            root->children[index]=nullptr;
        }
    }

    void removeword(string word){
        remove(root,word);
    }*/
     
};
