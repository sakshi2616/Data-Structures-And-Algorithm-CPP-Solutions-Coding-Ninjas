#include<bits/stdc++.h>
using namespace std;

int sum(int are[],int n){
    if(n==0){
        return 0;
    }
    return are[n-1]+sum(are,n-1);
}

int main(){
    int n;
    cin>>n;
    int are[n];
    for(int i=0;i<n;i++){
        cin>>are[i];
    }
    int output=sum(are,n);
    cout<<output;
}