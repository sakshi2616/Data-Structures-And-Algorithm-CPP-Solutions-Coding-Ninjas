#include<bits/stdc++.h>
using namespace std;

bool pali(string word, int len, int s,int e){
    bool output=true;
    if(s>e){
        return output;
    }
    if(word[s]!=word[e]){
        return false;
    }
    pali(word,len,s+1,e-1);
    return output;

}

int main(){
    string word;
    cin>>word;
    int len=word.size();
    bool output=pali(word,len,0,len-1);
    cout<<(output)<<endl;
}