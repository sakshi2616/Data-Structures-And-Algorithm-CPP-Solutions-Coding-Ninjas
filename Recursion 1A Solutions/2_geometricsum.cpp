#include<bits/stdc++.h>
using namespace std;

double geosum(int k,double s){
    if(k==0){
        return 1;
    }
    s=s*(0.5);
    return geosum(k-1,s)+s;
}

int main(){
    int k;
    cin>>k;
    double output=geosum(k,1);
    cout<<output<<endl;
}