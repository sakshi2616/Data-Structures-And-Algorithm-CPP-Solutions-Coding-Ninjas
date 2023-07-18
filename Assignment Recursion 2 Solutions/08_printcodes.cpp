#include<bits/stdc++.h>
using namespace std;

char getstring(char c){
    int l=c-'0';
    char d='a'+l-1;
    return d;
}

int getint(char c){
    int l=c-'0';
    return l;
}

char getchar(int i){
    char c= 'a'+i-1;
    return c;
}

void returncode(string input, string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    char t=getstring(input[0]);
    char y=getchar(getint(input[0])*10+getint(input[1]));

    returncode(input.substr(1), output+t);
    
    if(input.size()>1){
        returncode(input.substr(2), output+y);
    }
}

int main(){
    string input;
    cin>>input;
    string output="";
    returncode(input, output);
}