#include<bits/stdc++.h>
using namespace std;

int shortsubsequence(char input1[], char input2[], int m, int n){
    
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=j;
    }

    

}

int shortsubsequence(string s,string t){
    int m=s.length();
    int n=t.length();

    char input1[m];
    char input2[n];

    for(int i=0;i<m;i++){
        input1[i]=s[i];
    }

    for(int j=0;j<n;j++){
        input2[j]=t[j];
    }


    return shortsubsequence(input1,input2,m,n);
}



int shortsub(string s,string t,int n,int m){
    //int n=s.length();
    //int m=t.length();
    if(n==0){
        return INT_MAX-5;
    }

    if(m==0){
        return 1;
    }

    int ans=INT_MAX-5;
    int c=s[n-1];
    int j;
    for(j=m-1;j>=0;j--){
        if(t[j]==c){
            break;
        }
    }

    if(j==-1){
        ans=1;
    }

    else{
        ans=min(shortsub(s,t,n-1,m),shortsub(s,t,n-1,j)+1);
    }
    return ans;
    
}


int main(){
    string s;
    string t;
    int n=s.length();
    int m=t.length();
    cin>>s>>t;
    int ans=shortsub(s,t,n,m);
    cout<<ans<<endl;
}