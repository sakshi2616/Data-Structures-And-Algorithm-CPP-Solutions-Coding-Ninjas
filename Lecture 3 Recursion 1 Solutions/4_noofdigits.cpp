#include<bits/stdc++.h>
using namespace std;

int digits(int n){
    int count=0;
    if(n%10==0){
        return 0;
    }
    
    return 1+digits(n/10);
}

int main(){
    int n;
    cin>>n;
    
    int s=digits(n);
    cout<<s<<endl;
}