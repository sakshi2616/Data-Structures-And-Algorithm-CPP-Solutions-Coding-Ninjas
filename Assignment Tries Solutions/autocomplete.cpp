#include<bits/stdc++.h>
using namespace std;
#include"trie.h"

int main(){
    int n;
    cin>>n;
    Trie t;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        t.insertwordhelper(temp);
    }

    string s;
    cin>>s;

    TrieNode* temp=t.findword(s);
    if(temp==NULL){
        cout<<"idk"<<endl;
    }
    else{
        t.allpossible(temp,s);
    }

}