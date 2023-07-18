#include<bits/stdc++.h>
using namespace std;

void printpermu(string input, string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    
    for(int i=0;i<input.size();i++){
        printpermu(input.substr(0,i)+input.substr(i+1), output+input[i]);
    }
}

int main(){
    string input;
    cin>>input;
    string output;
    printpermu(input,output);
}