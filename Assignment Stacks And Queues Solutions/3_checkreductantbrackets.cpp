#include<bits/stdc++.h>
using namespace std;
#include<stack>

int main(){
    string s;
    cin>>s;
    stack<char> q;

    int l=s.length();
    int count=0;
    bool answer=false;

    for(int i=0;i<l;i++){
        if(s[i]==')'){
            while(q.top()!='('){
                q.pop();
                count++;
            }
            q.pop();
            if(count<=1){
                answer=true;
                break;
            }
            count=0;
        }
        else{
            q.push(s[i]);
        }
    }

    if(answer==true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}