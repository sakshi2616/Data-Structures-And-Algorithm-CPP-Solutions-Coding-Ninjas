#include<bits/stdc++.h>
using namespace std;

int findminvertex(int distance[], bool visited[], int n){
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(visited[i]==false && (minvertex==-1 || distance[i]<distance[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}   

void dijkstras(int**edges,int n){
    bool*visited=new bool[n];

    int*distance=new int[n];
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        visited[i]=false;
    }

    distance[0]=0;
    for(int i=0;i<n-1;i++){

        int minvertex=findminvertex(distance,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minvertex][j]!=0 && !visited[j]){
                int dist=distance[minvertex]+edges[minvertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }


    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }

    delete[]visited;
    delete[]distance;
}

int main(){
    int n;
    int e;
    cin>>n>>e;

    int**edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int [n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }

    cout<<endl;
    dijkstras(edges,n);

}