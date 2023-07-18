#include<bits/stdc++.h>
using namespace std;

int lis(int n, int input[]){
    int output[n];
    output[0]=1;
    for(int i=0;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(input[j]>input[i]){
                continue;
            }
            int possibleans=output[j]+1;
            if(possibleans>output[i]){
                output[i]=possibleans;
            }
        }
    }

    int best=0;
    for(int i=0;i<n;i++){
        if(best<output[i]){
            best=output[i];
        }
    }
    return best;
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<lis(n,input)<<endl;
}