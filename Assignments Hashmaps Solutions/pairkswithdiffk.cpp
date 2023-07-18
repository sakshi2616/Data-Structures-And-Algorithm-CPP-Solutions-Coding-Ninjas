#include<bits/stdc++.h>
using namespace std;

int noofpairs(int n, int input[], int diff){
    unordered_map<int, int> freq;
    for(int i=0;i<n;i++){
        if(freq.count(input[i])>0){
            freq[input[i]]++;
        }
        else{
            freq[input[i]]=1;
        }
    }

    if(diff==0){
        int count=0;

        
            unordered_map<int,int> :: iterator it=freq.begin();
            while(it!=freq.end()){
                int v=it->second;
                count+=(v*(v-1))/2;
                
                it++;
            }
        
        return count;
    }
    else{

    int count=0;
    for(int i=0;i<n;i++){
        if(freq.count(abs(input[i]-diff))>0){
            count+=(freq[input[i]]*freq[abs(input[i]-diff)]);
        }
    }

    return count/2;
    }
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int diff;
    cin>>diff;

    int ans=noofpairs(n,input,diff);
    cout<<ans<<endl;
}