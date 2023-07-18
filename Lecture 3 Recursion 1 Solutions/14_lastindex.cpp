#include<bits/stdc++.h>
using namespace std;

int lastindex(int are[], int n, int x, int curr,int index){
    
    if(curr==n){
        return index;
    }
    if(are[curr]==x){
        index=curr;
    }
    lastindex(are,n,x,curr+1,index);
}

int main(){
    int n;
    cin>>n;
    int are[n];
    for(int i=0;i<n;i++){
        cin>>are[i];
    }
    int x;
    cin>>x;
    int output=lastindex(are,n,x,0,-1);
    cout<<output;
}