#include<bits/stdc++.h>
using namespace std;
#include"trie.h"

string reverse(string s){
    string output=s;
    for(int i=0;i<(s.size()/2);i++){
        char w=output[i];
        output[i]=s[output.size()-i-1];
        output[output.size()-i-1]=w;
    }
    return output;

}

int main(){
    int n;
    cin>>n;
    Trie t;
    bool ans=false;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        t.insertwordhelper(temp);

        string temp2=reverse(temp);
        if(t.search(temp2)){
            ans=true;
        }
    }

    if(ans){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}
