#include<bits/stdc++.h>
using namespace std;

int trees(int h){
    if(h<=1){
        return 1;
    } 

    else{
        int mod=(int)(pow(10,9))+7;
        //int x=trees(h-1)*trees(h-1);
        //int y=trees(h-1)*trees(h-2);
        //int z=trees(h-2)*trees(h-1);

        //return x+y+z;

        int x=trees(h-1);
        int y=trees(h-2);

        int temp1=(int)(((long)(x)*x)%mod);
        int temp2=(int)((2*(long)(x)*y)%mod);
        int ans=(temp1+temp2)%mod;
        return ans;
        //return (x*x)+2*(x*y);
    }
}  

int main(){
    int h;
    cin>>h;

    cout<<trees(h)<<endl;
}