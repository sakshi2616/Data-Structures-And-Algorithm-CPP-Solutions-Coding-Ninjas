#include<bits/stdc++.h>
using namespace std;

void replace(char word[]){
    if(word[0]=='\0'){
        return;
    }
    if(word[1]=='\0'){
        return;
    }
    if(word[0]=='p' && word[1]=='i'){
        word[0]='3';
        word[1]='.';
        int len=strlen(word);
        for(int i=len+2;i>1;i--){
            word[i]=word[i-2];
        }
        word[2]='1';
        word[3]='4';
    }
    replace(word+1);
}

int main(){
    char word[100];
    cin.getline(word,100);
    replace(word);
    cout<<word<<endl;
}