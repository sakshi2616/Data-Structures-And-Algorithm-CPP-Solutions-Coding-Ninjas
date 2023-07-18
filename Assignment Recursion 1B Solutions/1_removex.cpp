#include<bits/stdc++.h>
using namespace std;

void modify(char word[]){
    int len=strlen(word);
    if(len==0){
        return;
    }
    if(word[0]!='x'){
        modify(word+1);
    }
    if(word[0]=='x'){
        int i=1;
        for(i;word[i]!='\0';i++){
            
            word[i-1]=word[i]; 
            
        }
        word[i-1]=word[i];
        modify(word);
    }
}   

int main(){
    char word[100];
    cin.getline(word,100);
    int len=strlen(word);
    modify(word);
    cout<<word;
}