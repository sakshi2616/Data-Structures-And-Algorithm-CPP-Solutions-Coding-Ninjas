#include<bits/stdc++.h>
using namespace std;

int maxsq(int n, int m, int**input){
    int dp[n][m];
    int ans=0;
    for(int i=0;i<n;i++){
        if(input[i][0]==0){
            dp[i][0]=1;
            if(dp[i][0]>ans){
                ans=dp[i][0];
            }
        }
        else{
            dp[i][0]=0;
        }
    }

    for(int j=1;j<m;j++){
        if(input[0][j]==0){
            dp[0][j]=1;
            ans=max(ans,dp[0][j]);
        }
        else{
            dp[0][j]=0;
        }
    }

    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(input[i][j]==1){
                dp[i][j]=0;
            }

            else{
                int x=dp[i-1][j-1];
                int y=dp[i-1][j];
                int z=dp[i][j-1];

                dp[i][j]=1+min(x,min(y,z));
                ans=max(dp[i][j],ans);
            }
        }
    }
    return ans;
    
}

int main(){
    int n,m;
    cin>>n>>m;

    int **input=new int*[n];
    for(int i=0;i<n;i++){
        input[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }

    cout<<maxsq(n,m,input)<<endl;
}