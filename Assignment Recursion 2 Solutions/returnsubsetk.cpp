#include<bits/stdc++.h>
using namespace std;

void subsum(int input[], int n, int k,int *output, int r, int c){
    
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[n];
    }
    int k;
    cin>>k;
    int output[n][n]={0};
    subsum(input,n,k,(int*)output,n,n);
    for(int i=0;output[i][0]!=0;i++){
        for(int j=0;output[i][j]!=0;j++){
            cout<<output[i][j];
        }
    }
}