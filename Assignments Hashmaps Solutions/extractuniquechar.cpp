#include<bits/stdc++.h>
using namespace std;

string getunique(string input){
    unordered_map<char,int> occur;
    for(int i=0;i<input.size();i++){
        if(occur.count(input[i])>0){
            input.erase(i,1);
            occur[input[i]]++;
        }
        
        occur[input[i]]=1;
        
    }
    return input;

}

int main(){
    string input;
    cin>>input;
    string output=getunique(input);
    cout<<output<<endl;
}