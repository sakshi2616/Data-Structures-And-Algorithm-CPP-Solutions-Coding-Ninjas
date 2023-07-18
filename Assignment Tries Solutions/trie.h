#include<bits/stdc++.h>
using namespace std;
#include "trienodeclass.h"

class Trie{
    TrieNode *root;
    public:

    Trie(){
       root=new TrieNode('\0');
    }

    void insertword(TrieNode* root,string word){
        //base case
        if(word.size()==0){
            root->isterminal=true;
            return;
        }

        //small calculations
        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=nullptr){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursive call
        insertword(child,word.substr(1));
    }

    //for user
    void insertwordhelper(string word){
        insertword(root,word);
    }

    bool search(TrieNode *root,string word) {
        
        if(root->children[word[0]-'a']==NULL)
            return false;

        if(word.size()==1)
        {
            return root->children[word[0]-'a']->isterminal;
        }

        return search(root->children[word[0]-'a'],word.substr(1)); 
    }

    bool search(string word)
    {  return search(root,word);}

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
    }

    //autocomplete question
    TrieNode* findword(TrieNode* root, string word){
        //base case
        if(word.size()==0){
            return root;
        }
        if(root->children[word[0]-'a']!=nullptr){
            return findword(root->children[word[0]-'a'],word.substr(1));
        }

        return nullptr;
    }

    TrieNode* findword(string word){
        return findword(root,word);
    }

    void allpossible(TrieNode* root,string word){
        if(root->isterminal){
            cout<<word<<endl;
        }

        for(int i=0;i<26;i++){
            if(root->children[i]!=nullptr){
                allpossible(root->children[i],word+(char)(i+'a'));
            }
        }
        return;
    }

    

};
