#include<bits/stdc++.h>
using namespace std;

void index(int are[], int n, int x, int curr){
    
    if(n==curr){
        return;
    }
    if(are[curr]==x){
        cout<<curr<<" ";
    }
    return index(are,n,x,curr+1);
    cout<<curr<<endl;
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
    index(are,n,x,0);
}