#include<bits/stdc++.h>
using namespace std;

vector<int> inters(int n, int *a, int m, int *b){
    vector<int> output;
    unordered_map<int, int> freq;
    for(int i=0;i<n;i++){
        if(freq.count(a[i])>0){
            freq[a[i]]++;
        }
        else{
        freq[a[i]]=1;
        }    
    }

    for(int i=0;i<m;i++){
        if(freq.count(b[i])>0){
            freq[b[i]]--;
            output.push_back(b[i]);
        }
    }
    return output;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }

        int m;
        cin>>m;
        int b[m];
        for(int j=0;j<m;j++){
            cin>>b[j];
        }

        vector<int> output=inters(n,a,m,b);
        for(int j=0;j<output.size();j++){
            cout<<output[j]<<" ";
        }
    }
}