#include<bits/stdc++.h>
using namespace std;

bool checkmh(int input[], int n){
    int ans=true;
    int parent=0;
    int left=1;
    int right=2;
    while(left<n){
        if(input[left]>input[parent]){
            ans=false;
            break;
        }
        if(input[right]>input[parent] && right<n){
            ans=false;
            break;
        }
        parent++;
        left=(2*parent)+1;
        right=(2*parent)+2;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    bool output=checkmh(input,n);
    cout<<output<<endl;
}