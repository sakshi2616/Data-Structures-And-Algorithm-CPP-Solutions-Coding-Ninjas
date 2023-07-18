#include<bits/stdc++.h>
using namespace std;

int kthl(int input[], int n,int k){
    priority_queue<int,vector<int>,greater<int>> small;
    
    for(int i=0;i<k;i++){
        small.push(input[i]);
    }

    for(int i=k;i<n;i++){
        int temp=small.top();
        if(input[i]>temp){
            //cout<<temp<<endl;
            small.pop();
            small.push(input[i]);
        }
    }
    
    return small.top();
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int k;
    cin>>k;

    int ans=kthl(input,n,k);
    cout<<ans<<endl;
}