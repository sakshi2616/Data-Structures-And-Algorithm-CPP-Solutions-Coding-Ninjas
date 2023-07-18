#include<bits/stdc++.h>
using namespace std;

int maxf(int *input, int n){
    unordered_map<int, int> freq;
    for(int i=0;i<n;i++){
        if(freq.count(input[i])>0){
            freq[input[i]]++;
        }
        else{
        freq[input[i]]=1;
        }
        int max=0;
        int no;
        for(int i=0;i<n;i++){
            if(freq[input[i]]>max){
                max=freq[input[i]];
                no=input[i];
            }
        }
        return no;
    }
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int ans=maxf(input,n);
    cout<<ans<<endl;
}