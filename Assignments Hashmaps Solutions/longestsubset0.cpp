#include<bits/stdc++.h>
using namespace std;

int zerosum(int n, int input[]){
    unordered_map<int,int> help;
    int s=0;
    int maxl=0;
    for(int i=0;i<n;i++){
        s=s+input[i];
        
        if(help.count(s)==0){
            help[s]=i;
        }
        else{
            maxl=max(maxl,i-help[s] );
        }
    }
    return maxl;
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    int ans=zerosum(n,input);
    cout<<ans<<endl;
}