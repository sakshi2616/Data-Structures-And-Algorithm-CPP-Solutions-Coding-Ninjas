#include<iostream>
using namespace std;

void subset(int array[], int n, int output[], int m){
    if(n<=0){
        for(int j=0;j<m;j++){
            cout<<output[j]<<" ";
            
        }
        cout<<endl;
        return;
    }
    int newoutput[m+1];
    newoutput[m]=array[0];
    for(int k=0;k<m;k++){
        newoutput[k]=output[k];
    }
    subset(array+1,n-1,newoutput,m+1);
    subset(array+1,n-1,output,m);
}


int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int output[n];
    subset(array,n, output,0);
}