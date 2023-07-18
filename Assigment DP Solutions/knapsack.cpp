#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int*weight, int*values, int maxw){
    //base case
    if (n==0 ||maxw==0){
        return 0;
    }
    if(weight[0]>maxw){
        return knapsack(n-1,weight+1,values+1,maxw);
    }
    

    int a=values[0]+knapsack(n-1,weight+1,values+1,maxw-weight[0]);
    int b=knapsack(n-1,weight+1,values+1,maxw);
    int ans=max(a,b);
    return ans;
}

int knapsack_dp(int n, int*weight, int *values,int maxw){
    vector<vector<int> > output(n + 1, vector<int>(maxw + 1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxw;j++){
            if(i==0 || j==0){
                output[i][j]=0;
            }
            else if(weight[i-1]<=j){
                output[i][j]=max(values[i-1]+output[i-1][j-weight[i-1]],output[i-1][j]);
            }
            else{
                output[i][j]=output[i-1][j];
            }

        }
    }
    return output[n][maxw];

}

int main(){
    int n;
    cin>>n;

    int *weight=new int[n];
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    int *values=new int[n];
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    int maxw;
    cin>>maxw;

    cout<<knapsack(n,weight,values,maxw)<<endl;

}