#include<bits/stdc++.h>
using namespace std;

int loot(int n, int profit[]){
    int dp[n];
    dp[0]=profit[0];
    dp[1]=max(profit[0],profit[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(profit[i]+dp[i-2],dp[i-1]);
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    int profit[n];
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }

    int ans=loot(n,profit);
    cout<<ans<<endl;
}