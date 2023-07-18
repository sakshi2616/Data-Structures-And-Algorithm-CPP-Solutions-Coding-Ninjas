#include<bits/stdc++.h>
using namespace std;



int possible(int a,int b, int help){
    int temp=a-pow(help,b);

    if(temp==0){
        return 1;
    }
    if(temp<0){
        return 0;
    }
    return possible(a,b,help+1)+possible(temp,b,help+1);

}

int possible(int a, int b){
    return possible(a,b,1);
}

int main(){
    int a,b;
    cin>>a>>b;

    int ans=possible(a,b);
    cout<<ans<<endl;
}