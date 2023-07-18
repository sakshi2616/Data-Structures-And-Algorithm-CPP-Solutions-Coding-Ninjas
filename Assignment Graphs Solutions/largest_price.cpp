
#include<bits/stdc++.h>
using namespace std;

int cake_helper(int**input,bool**visited, int i,int j,int n){
    int xdir[] = {0,1,-1,0}; 
    int ydir[] = {1,0,0,-1}; 

    int max=0;
    visited [i][j]=true;
    for(int k=0;k<4;k++){
        int x=i+xdir[k];
        int y=j+ydir[k];
        if(0<=x<n && 0<=y<n && !visited[x][y] && input[x][y]==1){
            int smallans=cake_helper(input,visited,x,y,n);
            max=max+smallans;
        }
    }
    return max+1;
}

int cake(int n, int**input, bool** visited){
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && input[i][j]==1){
                int ans=cake_helper(input,visited,i,j,n);
                if(max<ans){
                    max=ans;
                }
            }
        }
    }
    return max;
}



int main(){
    int n;
    cin>>n;

    int**input=new int*[n];
    bool**visited=new bool*[n];
    for(int i=0;i<n;i++){
        input[i]=new int[n];
        visited[i]=new bool[n];
        for(int j=0;j<n;j++){
            cin>>input[i][j];
            visited[i][j]=false;
        }
    }

    int ans=cake(n,input,visited);
    cout<<ans<<endl;
    
}