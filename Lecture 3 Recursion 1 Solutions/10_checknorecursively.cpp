#include<bits/stdc++.h>
using namespace std;

bool check(int are[], int n, int x){
    if(n==0){
        return false;
    }
    if(are[n]==x){
        return true;
    }
    check(are,n-1,x);
}

int main(){
    int n;
    cin>>n;
    int are[n];
    for(int i=0;i<n;i++){
        cin>>are[i];
    }
    int x;
    cin>>x;
    bool output=check(are,n,x);
    cout<<output<<endl;
}