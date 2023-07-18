#include<bits/stdc++.h>
using namespace std;

void getpath_bfs(int **edges, int n, int s, int e, bool visited[], unordered_map<int, int> path){
    visited[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(visited[i]==false && edges[u][i]==1){
                visited[i]=true;
                q.push(i);
                path[i]=u;
                if(i==e){
                    break;
                }
            }
        }
    }

    if(path.count(e)>0){
        int i=e;
        cout<<e<<" ";
        while(i!=0){
            cout<<path[i]<<" ";
            i=path[i];
        }
    }

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
    
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    unordered_map<int,int> path;

    getpath_bfs(edges,n,x,y,visited,path);

}