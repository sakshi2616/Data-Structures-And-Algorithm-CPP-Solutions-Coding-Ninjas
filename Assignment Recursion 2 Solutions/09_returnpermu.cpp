#include<bits/stdc++.h>
using namespace std;

int getpermu(string input, string output[]){
    if(input.size()==0){
        output[0]="";
        return 1;
    }
    string output1[1000];
    int smalloutput= getpermu(input.substr(1), output1);
    int k=0;
    for(int i=0;i<smalloutput;i++){
        for(int j=0; j<=output1[i].size(); j++){
            output[k++]=output1[i].substr(0,j)+input[0]+output1[i].substr(j);
        }
    }
    return k;
}

int main(){
    string input;
    cin>>input;
    string output[1000];
    int t=getpermu(input, output);
    for(int i=0;i<t;i++){
        cout<<output[i]<<endl;
    }
}