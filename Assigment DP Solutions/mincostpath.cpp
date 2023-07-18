#include<bits/stdc++.h>
using namespace std;

int cost(int m, int n, int **input, int i,int j){
    //base
    if(i==m-1 && j==n-1){
        return input[i][j];
    } 
    if(i>=m || j>=m){
        return INT_MAX;
    }

    //recursive(time complexity-exponential)
    int x=cost(m,n,input,i,j+1);
    int y=cost(m,n,input,i+1,j+1);
    int z=cost(m,n,input,i+1,j);

    //small calc
    int ans=min(x,min(y,z))+input[i][j];
    return ans;
}

int cost(int m, int n, int **input){
    return cost(m,n,input,0,0);
}

//memoization
int cost_memo(int m, int n, int **input, int i,int j,int **output){
    //base
    if(i==m-1 && j==n-1){
        return input[i][j];
    } 
    if(i>=m || j>=m){
        return INT_MAX;
    }
    //CHECK IF ANS EXISTS
    if(output[i][j]!=-1){
        return output[i][j];
    }

    //recursive(time complexity-exponential)
    int x=cost_memo(m,n,input,i,j+1,output);
    int y=cost_memo(m,n,input,i+1,j+1,output);
    int z=cost_memo(m,n,input,i+1,j,output);

    //small calc
    int ans=min(x,min(y,z))+input[i][j];
    output[i][j]=ans;
    return ans;

}

int cost_memo(int m,int n,int **input,int i,int j){
    int **output=new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=-1;
        }
    }

    return cost_memo(m,n,input,i,j,output);
}

int cost_dp(int m, int n, int **input){
    int **output=new int*[m];
    for(int i=0;i<n;i++){
        output[i]=new int[n];
    }
    //fill the last cell 
    output[m-1][n-1]=input[m-1][n-1];

    //fill last row(right to left)
    for(int j=n-2;j>=0;j--){
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    }

    //fill lat col(bot to top)
    for(int i=m-2;i>=0;i--){
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }

    //fill remaining cells
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j]=min(output[i][j+1], min(output[i+1][j+1], output[i+1][j]))+input[i][j];
        }
    }

    return output[0][0];
}




int main(){
    int m,n;
    cin>>m>>n;
    int**input=new int*[m];
    //int input[m][n];
    for(int i=0;i<m;i++){
        input[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }

    cout<<cost(m,n,input)<<endl;
    cout<<cost_memo(m,n,input,0,0)<<endl;
    cout<<cost_dp(m,n,input)<<endl;
}