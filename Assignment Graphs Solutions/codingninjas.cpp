#include<bits/stdc++.h>
using namespace std;

bool has_path(int n,int m, char**input, bool**visited, string find, int i, int j){
    if(find.length()==0){
        visited[i][j]=true;
        return true;
    }

    visited[i][j]=true;
    int x[]={-1,1,0,0,1,-1,1,-1};
    int y[]={0,0,-1,1,1,-1,-1,1};

    for(int k=0;k<8;k++){
        int r=i+x[k];
        int s=j+y[k];

        if(r>=0 && s>=0 && r<n && s<m && input[r][s]==find[0] && !visited[r][s]){
            bool smallans=has_path(n,m,input,visited,find.substr(1),r,s);
            if(smallans){
                return smallans;
            }
        }
    }

    visited[i][j]=false;
    return false;
    
}


bool cn(int n, int m, char**input, bool**visited){
    string find="CODINGNINJA";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(input[i][j]=='C'){
                bool temp=has_path(n,m,input,visited,find.substr(1),i,j);
                if(temp){
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    char**input=new char*[n];
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++){
        input[i]=new char[m];
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }

    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }

    bool ans=cn(n,m,input,visited);
    cout<<ans<<endl;


}