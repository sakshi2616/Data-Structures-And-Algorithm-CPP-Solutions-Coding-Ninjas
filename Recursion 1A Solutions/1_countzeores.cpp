#include<bits/stdc++.h>
using namespace std;

int zeroes(int n,int count){
    if(n==0){
        return count;
    }
    if(n%10==0){
        count++;
    }
    return zeroes(n/10,count);
    
}

int main(){
    int n;
    cin>>n;
    int output=zeroes(n,0);
    cout<<output<<endl;
}