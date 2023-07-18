#include<iostream>
using namespace std;

inline int max(int a,int b){
    return(a>b)? a:b;
}

int main(){
    int a,b;
    cin>>a>>b;

    /*int c;
    if(a>b){
        c=a;
    }
    else{
        c=b;
    } to find max*/

    //alt method:
    int c=(a>b) ? a:b; // (condn)? (if):else; //max fn

    int x,y;
    x=12;
    y=34;
    int z=max(x,y); //second option
    cout<<z;
}