#include<bits/stdc++.h>
using namespace std;

//dfs traversal
void print_dfs(int**edges,int n, int sv, bool *visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            print_dfs(edges,n,i,visited);
        }
    }
}

//bfs traversal
void print_bfs(int **edges, int n, int sv, bool*visited){
    queue<int>q;
    q.push(sv);
    visited[sv]=true;


    while(!q.empty()){
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0;i<n;i++){
            if(i==u){
                continue;
            }
            if(edges[u][i]==1){
                if(visited[i]){
                    continue;
                }
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void dfs(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
        print_dfs(edges,n,i,visited);
        }

    }

    delete[]visited;
}

void bfs(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
        print_bfs(edges,n,i,visited);
        }

    }

    delete[]visited;
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

    
    cout<<"bfs"<<endl;
    bfs(edges,n);

    cout<<"dfs"<<endl;
    dfs(edges,n);
    

}