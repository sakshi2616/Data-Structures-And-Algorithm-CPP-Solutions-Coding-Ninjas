#include<bits/stdc++.h>
using namespace std;
#include<stack>

int main(){
    string s;
    cin>>s;
    stack<char> q;

    int l=s.length();
    
    for(int i=0;i<l;i++){
        if(s[i]=='}'){
            if(!q.empty()){
                q.pop();
            }
        }
        else if(s[i]=='{'){
            q.push(s[i]);
        }
    }

    int si=q.size();
    if(si%2==0){
        cout<<si/2<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}