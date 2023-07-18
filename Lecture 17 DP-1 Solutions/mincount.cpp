#include<bits/stdc++.h>
using namespace std;

int mincount(int n){
    int ans[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;

    for(int i=4;i<=n;i++){
        int t=sqrt(i);
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int j=1;j<=t;j++){
            pq.push(1+ans[i-(j*j)]);
        }
        ans[i]=pq.top();
        while(!pq.empty()){
            pq.pop();
        }
    }
    return ans[n];
}

int main(){
    int n;
    cin>>n;

    int ans=mincount(n);
    cout<<ans<<endl;
}

