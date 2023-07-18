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

int returncode(string input, string output[]){
    if(input.size()==0){
        output[0]="";
        return 1;
    }
    if(input.size()==1){
        output[0]=getstring(input[0]);
        return 1;
    }


    string output1[1000];
    string output2[1000];
    int smalloutput1=returncode(input.substr(1), output1);
    int smalloutput2=0;

    if(input.size()>1){
        if((getint(input[0]))*10+getint(input[1])>=10 && (getint(input[0]))*10+getint(input[1])<27 ){
            smalloutput2=returncode(input.substr(2),output2);
        }
    }
    int k=0;
    for(int i=0;i<smalloutput1;i++){
        output[i]=getstring(input[0])+output1[i];
        k++;
    }
    for(int i=0;i<smalloutput2;i++){
        output[k]=getchar((getint(input[0]))*10+getint(input[1]))+output2[i];
        k++;
    }
    return k;

}

int main(){
    string input;
    cin>>input;
    string* output= new string[1000];
    int t=returncode(input, output);
    for(int i=0;i<t;i++){
        cout<<output[i]<<endl;
    }
}