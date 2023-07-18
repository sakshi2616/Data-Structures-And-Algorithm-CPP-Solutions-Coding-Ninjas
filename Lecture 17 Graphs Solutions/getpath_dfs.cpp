#include<bits/stdc++.h>
using namespace std;


vector<int> getpath_dfs(int **edges,int n,int x,int y,bool visited[]){
    visited[x]=true;
    vector<int>ans;
    if(x==y){
        ans.push_back(x);
        return ans;
    }

    if(edges[x][y]==1){
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }

    for(int i=0;i<n;i++){
        if(visited[i]==false && edges[x][i]==1){
            vector<int> temp2=getpath_dfs(edges,n,i,y,visited);
            if(temp2.size()){
                temp2.push_back(x);
                return temp2;
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
    
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    vector<int>output=getpath_dfs(edges,n,x,y,visited);
    if(output.size()){
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
    }
}