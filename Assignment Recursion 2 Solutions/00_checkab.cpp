#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    
    if(s[0]=='\0'){
        return true;
    }
    else if(s[0]=='b'){
        if(s[1]!='b'){
            return false;
        }
        else{
            if(s[2]=='b'){
                return false;
            }
            else{
                check(s.substr(2));
            }
        }
    }
    else if(s[0]=='a'){
        if(s[1]='b' && s[2]!='b'){
            return false;
        }
        else{
            check(s.substr(1));
        }
    }
}

int main(){
    string s;
    cin>>s;
    if(s[0]=='a'){
        if(check(s.substr(1))){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
    else{
        cout<<"false"<<endl;
    }
}