#include<iostream> // #include is pre-processor director
using namespace std;
#define PI 3.14 // going to find everywhere PI is written and will replace it with 3.14

int main(){
    int r;
    cin>>r;
    cout<<PI*r*r<<endl;
}