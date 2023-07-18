#include<bits/stdc++.h>
using namespace std;

int modify(string word, int len,int c,int number,int k){
    
    if(len==0){
        return (word[0]-'0');
    }
    number=number+(((word[c])-'0')*pow(10,k));
    cout<<number<<endl;
    modify(word,len-1,c-1,number,k+1);
    return number;
}

int main(){
    string word;
    cin>>word;
    int len=word.size();
    int output=modify(word,len,len-1,0,0);
    cout<<output<<endl;
}