#include<bits/stdc++.h>
using namespace std;

int pairzero(int *a, int n){
    int ans=0;
    unordered_map<int,int> s;
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            if(s.count(a[i])>0){
                s[a[i]]++;
            }
            else{
                s[a[i]]=1;
            }
        }
        
    }

    for(int i=0;i<n;i++){
        if(a[i]<0){
            ans=ans+s[-(a[i])];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans=pairzero(a,n);
    cout<<ans<<endl;
}