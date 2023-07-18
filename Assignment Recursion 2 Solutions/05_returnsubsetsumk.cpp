#include<bits/stdc++.h>
using namespace std;

int subsum(int array[], int n, int x, int output[][100]){
    if(n==0){
        if(x==0){
            output[0][0]=0;
            return 1;
        }
        else{
            return 0;
        }
    }
    
    
    int si=subsum(array+1,n-1,x,output);
    int sj=subsum(array+1,n-1,x-array[0],output+si);

    for(int i=si;i<(si+sj);i++){
        for(int j=output[i][0];j>0;j--){
            output[i][j+1]=output[i][j];

        }
        output[i][1]=array[0];
        output[i][0]++;
    }
    
    return si+sj;
}

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int p=0;p<n;p++){
        cin>>array[p];
    }
    int x;
    cin>>x;
    int output[100][100];
    int nor=subsum(array,n,x,output);
    for(int i=0;i<nor;i++){
        for(int j=1;j<=output[i][0];j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}