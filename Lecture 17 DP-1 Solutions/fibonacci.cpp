#include<bits/stdc++.h>
using namespace std;

//recrusion
int fibo(int n){
    if(n<=1){
        return n;
    }

    int a=fibo(n-1);
    int b=fibo(n-2);
    return a+b;
}

//memoization(top-down),recursively
int fibo2(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}

int fibo_helper(int n, int *ans){
    if(n<=1){
        return n;
    }
     
    //check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }
    int a=fibo_helper(n-1,ans);
    int b=fibo_helper(n-2,ans);

    //save for future use
    ans[n]=a+b;

    //return the final output
    return ans[n];
    
} 

// DP tabulations(fill smallest problem firs tthen move iteratively)
int fibo3 (int n){
    int *ans=new int[n+1];

    ans[0]=0;
    ans[1]=1;

    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
}