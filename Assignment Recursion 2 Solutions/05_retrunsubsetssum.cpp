#include<bits/stdc++.h>
using namespace std;

int sum(int answer[][100], int r){
    int sum1=0;
    for(int j=1;j<answer[r][0];j++){
        sum1+=answer[r][j];
    }
    return sum1;
}

int subset(int array[], int n, int answer[][100]){
    if(n<=0){
        answer[0][0]=0;
        return 1;
    }

    int snor=subset(array+1,n-1,answer);
    for(int i=0;i<snor;i++){
        int col=answer[i][0]+1;
        answer[i+snor][0]=col;
        
        for(int j=(answer[i][0]+1);j>1;j--){
            answer[i+snor][j]=answer[i][j-1];
        }
        answer[i+snor][1]=array[0];
    }
    return 2*(snor);
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
    int answer[100][100];
    int nor=subset(array,n,answer);
    for(int i=0;i<nor;i++){
        int l=sum(answer,i);
        if(l==x){
            for(int s=1;s<=answer[i][0];s++){
                cout<<answer[i][s]<<" ";
            }
            cout<<endl;
        }
        
    }
}