#include<bits/stdc++.h>
using namespace std;

//brute force
int minsteps(int n){
    if(n==1){
        return 0;
    }
    int x=minsteps(n-1);
    int y=INT_MAX;
    int z=INT_MAX;
    if(n%2==0){
        y=minsteps(n/2);
    }
    if(n%3==0){
        z=minsteps(n/3);
    }

    int ans=min(x,min(y,z))+1;
}

//memoization
int minsteps2(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return minsteps2helper(n,ans);
}

int minsteps2helper(int n, int ans[]){
    //base case
    if(n<=1){
        return 0;
    }

    //check if op aleady exists
    if(ans[n]!=-1){
        return ans[n];
    }

    //calculate
    int x=minsteps2helper(n-1,ans);
    int y=INT_MAX;
    int z=INT_MAX;
    if(n%2==0){
        y=minsteps2helper(n/2,ans);
    }
    if(n%3==0){
        z=minsteps2helper(n/3,ans);
    }

    int output=min(x,min(y,z))+1;
    ans[n]=output;
    return output;
}

int main(){
    int n;
    cin>>n;

    cout<<minsteps(n)<<endl;
}