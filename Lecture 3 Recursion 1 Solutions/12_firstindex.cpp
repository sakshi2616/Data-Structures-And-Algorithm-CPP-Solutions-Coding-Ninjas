#include<bits/stdc++.h>
using namespace std;

int index(int are[], int n, int x, int curr){
    
    if(n==curr){
        return -1;
    }
    if(are[curr]==x){
        return curr;
    }
    return index(are,n,x,curr+1);
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
    int output=index(are,n,x,0);
    cout<<output<<endl;
}