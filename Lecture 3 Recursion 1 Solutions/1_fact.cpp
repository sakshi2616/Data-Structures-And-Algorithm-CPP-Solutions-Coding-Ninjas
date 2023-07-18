#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    int x=factorial(n-1);
    return n*x;
}
//CALL STACK
int main(){
    int n;
    cin>>n;
    int output=factorial(n);
    cout<<output<<endl;
}