#include<bits/stdc++.h>
using namespace std;

int stair(int n){
    if(n>=0){
        if(n==1 || n==0){
            return 1;
        }
        else{
            int x=stair(n-1);
            int y=stair(n-2);
            int z=stair(n-3);
            return x+y+z;
        }
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<stair(n)<<endl;
}