#include<bits/stdc++.h>
using namespace std;

int sum(int n, int c){
    if(n==0){
        return c;   
    }
    c+=n%10;
    sum(n/10,c); 
}

int main(){
    int n;
    cin>>n;
    int output=sum(n,0);
    cout<<output<<endl;
}