#include<bits/stdc++.h>
using namespace std;

vector<int> getpath_bfs(int **edges, int n,int h, bool visited[]){

    visited[h]=true;
    queue<int> q;
    q.push(h);

    vector<int> temp;
    temp.push_back(h);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(visited[i]==false && edges[u][i]==1){
                temp.push_back(i);
                visited[i]=true;
                q.push(i);
            }
        }
    }
    return temp;
}

int connected_helper(int **edges,int n, bool visited[]){
    int count=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            vector<int> temp=getpath_bfs(edges,n,i,visited);
            //output.push_back(temp);
            count++;
        }
    }

    return count;
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

    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    int ans=connected_helper(edges,n,visited);
    cout<<ans<<endl;

}