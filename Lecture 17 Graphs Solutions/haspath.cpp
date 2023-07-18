#include<bits/stdc++.h>
using namespace std;

bool haspath(int **edges, int n,int x,int y){
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    if(edges[x][y]==1){
        return true;
    }

    bool ans=false;

    queue<int> q;
    q.push(x);
    visited[x]=true;

    while(!q.empty()){
        int u=q.front();
        if(u==y){
            ans=true;
            break;
        }
        q.pop();
        for(int i=0;i<n;i++){
            if(i==u){
                continue;
            }
            if(edges[u][i]==1 &&visited[i]==false){
                q.push(i);
                visited[i]=true;

            }
        }
    }
    return ans;

}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int**edges=new int*[n];

    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    int x,y;
    cin>>x>>y;
    bool ans=haspath(edges,n,x,y);
    cout<<ans<<endl;
}