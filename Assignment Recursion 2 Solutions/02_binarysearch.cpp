#include<bits/stdc++.h>
using namespace std;

int binary(int array[], int x, int si, int ei){
    if(si>ei){
        return -1;
    }
    else{
        int mid=(si+ei)/2;
        if(x==array[mid]){
            return mid;
        }
        else if(x>array[mid]){
            return binary(array,x,mid+1,ei);
        }
        else{
            return binary(array,x,si,mid-1);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int x;
    cin>>x;
    int answer= binary(array,x,0,n-1);
    cout<<answer<<endl;
}