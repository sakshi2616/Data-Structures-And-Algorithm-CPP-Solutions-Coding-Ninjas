#include<bits/stdc++.h>
using namespace std;

int power(int x,int n){
    if(n==1){
        return x;
    }
    int s=power(x,n-1); 
    return x*s;
}

int main(){
    int x,n;
    cin>>x>>n;
    int output=power(x,n);
    cout<<output<<endl;
}