#include<bits/stdc++.h>
using namespace std;

void pairstar(char word[], int len){
    if(len==0){
        return;
    }
    if(word[0]==word[1]){
        for(int i=1;i<len;i++){
            
            word[i+1]=word[i];
        }
        word[1]='*';
    }
    pairstar(word+1,len-1);
}

int main(){
    char arr[100];
    cin.getline(arr,100);
    int len=strlen(arr);
    pairstar(arr,len);
    cout<<arr<<endl;
}