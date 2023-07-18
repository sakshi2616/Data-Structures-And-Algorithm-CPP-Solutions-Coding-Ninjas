#include<bits/stdc++.h>
using namespace std;

bool sorted(int are[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(are[0]>are[1]){
        return false;
    }
    bool s=sorted(are+1,n-1);
    return s;

}

int main(){
    int n;
    cin>>n;
    int are[n];
    for(int i=0;i<n;i++){
        cin>>are[i];
    }
    bool output=sorted(are,n);
    cout<<output<<endl;
    
}