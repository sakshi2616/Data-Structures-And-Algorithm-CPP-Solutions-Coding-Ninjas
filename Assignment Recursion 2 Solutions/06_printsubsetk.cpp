#include<bits/stdc++.h>
using namespace std;

void subsum(int input[], int n, int k, int output[], int m){
    if(n==0){
        if(k==0){
            for(int j=0;j<m;j++){
                cout<<output[j]<<" ";
            } 
            cout<<endl;
            return; 
        }
        return;
    }
    int newoutput[m+1];
    newoutput[m]=input[0];
    for(int k=0;k<m;k++){
        newoutput[k]=output[k];
    }
    subsum(input+1,n-1,k-input[0],newoutput,m+1);
    subsum(input+1,n-1,k,output,m);
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int k;
    cin>>k;
    int output[n];
    subsum(input,n,k,output,0);
}