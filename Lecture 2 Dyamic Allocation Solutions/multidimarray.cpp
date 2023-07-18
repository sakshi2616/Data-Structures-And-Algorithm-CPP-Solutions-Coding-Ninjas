#include<iostream>
using namespace std;

int main(){
    //creating a 2d array
    int m,n;
    cin>>m>>n;
    int **p=new int *[m]; //array of integer pointers
    for(int i=0;i<m;i++){
        p[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>p[i][j];
        }
    }
    //not all rows need to have same columns
    //we can make stair pattern
    /* for(int i=0;i<m;i++){
        p[i]=new int[i+1];
        for(int j=0;j<n;j++){
            cin>>p[i][j];
        }
    } */

    //deallocating memory
    for(int i=0;i<m;i++){
        delete[]p[i];
    }
    delete[]p; //pehle rows deleted, fer integer pointer array deleted
}