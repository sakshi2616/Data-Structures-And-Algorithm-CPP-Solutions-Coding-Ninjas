#include<bits/stdc++.h>
using namespace std;


#include"strie.h"

int main(){
    int n;
    cin>>n;
    Trie t;


    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        t.insertwordhelper(temp);
    }

    string pat;
    cin>>pat;

    cout<<t.search(pat)<<endl;
}