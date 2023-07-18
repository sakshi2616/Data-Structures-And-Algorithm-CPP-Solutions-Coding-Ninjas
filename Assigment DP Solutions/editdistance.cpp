#include<bits/stdc++.h>
using namespace std;

int editdis(string s,string t){
    
    //base case
    if(s.size()==0 || t.size()==0){
        return max(s.size(),t.size());
    }

    //recursive calls
    if(s[0]==t[0]){
        return editdis(s.substr(1),t.substr(1));
    }

    else{
    //insert
    int a=1+editdis(s.substr(1),t);
    //delete
    int b=1+editdis(s,t.substr(1));
    //replace
    int c=1+editdis(s.substr(1),t.substr(1)); 

    return min(a,min(b,c));
    }
}

int editdist_memo(string s,string t, int **output){

    int m=s.size();
    int n=t.size();

    //base case
    if(m==0 || n==0){
        output[m][n]=max(m,n);
    }

    if(output[m][n]!=-1){
        return output[m][n];
    }

    //recursive calls
    if(s[0]==t[0]){
        output[m][n]= editdist_memo(s.substr(1),t.substr(1),output);
    }

    

    else{
    //insert
    int a=1+editdist_memo(s.substr(1),t,output);
    //delete
    int b=1+editdist_memo(s,t.substr(1),output);
    //replace
    int c=1+editdist_memo(s.substr(1),t.substr(1),output); 

    output[m][n]= min(a,min(b,c));
    }

    return output[m][n];
}

int editdist_memo(string s,string t){
    int m=s.size();
    int n=t.size();

    int **output=new int *[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }

    return editdist_memo(s,t,output);
}

int dist_dp(string s,string t){
    int m=s.size();
    int n=t.size();

    int **output=new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n];
    }

    //fill the first row
    for(int j=0;j<=n;j++){
        output[0][j]=j;
    }
    //fill the first col
    for(int i=0;i<=m;i++){
        output[i][0]=i;
    }

    //fill remaining
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                output[i][j]=output[i-1][j-1];
            }
            else{
                int a=1+output[i-1][j];
                int b=1+output[i][j-1];
                int c=1+output[i-1][j-1];
                output[i][j]=min(a,min(b,c));
            }    
        }
    }
    //return reqd
    return output[m][n];

}


int main(){
    string s;
    string t;
    cin>>s>>t;
    cout<<dist_dp(s,t)<<endl;
}