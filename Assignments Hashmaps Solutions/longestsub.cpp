#include<bits/stdc++.h>
using namespace std;

pair<int,int> longsubseq(int n, int input[]){
    unordered_map<int,bool> helper;
    for(int i=0;i<n;i++){
        helper[input[i]]=true;
    }

    int maxl=0;
    int start=0;

    for(int i=0;i<n;i++){
        if(helper[input[i]]==false){
            continue;
        }
        else{
            int curr=1;
            int k=1;
            int temps=input[i];
            while(k<n){
                if(helper.count(input[i]+k)>0){
                    helper[input[i]+k]=false;
                    curr++;
                    k++;
                }
                else{
                    break;
                }
            }
            while(k<n){
                if(helper.count(input[i]-k)>0){
                    helper[input[i]-k]=false;
                    curr++;
                    temps--;
                    k++;

                }
                else{
                    break;
                }
            }
            helper[input[i]]=false;
            if(maxl<curr){
                maxl=curr;
                start=temps;
            }

        }
    }

    pair<int,int> output;
    output.first=maxl;
    output.second=start;
    return output;
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    pair<int, int> ans=longsubseq(n, input);
    cout<<ans.first<<" "<<ans.second<<endl;
}