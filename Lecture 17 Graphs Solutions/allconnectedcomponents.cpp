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

vector<vector<int>>connected_helpet(int **edges,int n, bool visited[]){
    vector<vector<int>> output;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            vector<int> temp=getpath_bfs(edges,n,i,visited);
            output.push_back(temp);
        }
    }

    return output;
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


    vector<vector<int>> output=connected_helpet(edges,n,visited);
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }

}