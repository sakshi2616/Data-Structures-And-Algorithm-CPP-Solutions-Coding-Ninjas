#include<iostream>
using namespace std;

int sum(int *a,int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans+=a[i];
    }
    return ans;
    
}

int main(){
    int a[10]={1,1,1,1,1,1,1,1,1,1};
    cout<<sum(a+3,7)<<endl; //upar a goes as a pointer not a array
    //a[5]=*(a+5)
    // we can pass part of array to a fn using pointer
    

}