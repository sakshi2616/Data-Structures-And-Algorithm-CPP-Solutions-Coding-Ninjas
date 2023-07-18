#include<bits/stdc++.h>
using namespace std;

bool hascycle(char**input, int fromx, int fromy, int i, int j, bool**visited, int n, int m){
    if(visited[i][j]=true){
        return true;
    }

    int xdirn[]={1,0,0,-1};
    int ydirn[]={0,1,-1,0};

    visited[i][j]=true;
    for(int k=0;k<4;k++){
        int x=xdirn[k]+i;
        int y=ydirn[k]+j;
        if(x==fromx && y==fromy){
            continue;
        }
        if(0<=x<n && 0<=y<m && input[x][y]==input[i][j]){
            bool smallans=hascycle(input,i,j,x,y,visited,n,m);
            if(smallans){
                return true;
            }
        }
    }

    return false;
}

bool dots(int n,int m, char **input, bool**visited){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                if(hascycle(input,-1,-1,i,j,visited,n,m)){
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

    char **input=new char*[n];
    for(int i=0;i<n;i++){
        input[i]=new char[m];
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }


    bool**visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }

    bool ans=dots(n,m,input,visited);
    cout<<ans<<endl;

}