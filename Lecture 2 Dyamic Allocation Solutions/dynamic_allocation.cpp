#include<iostream>
using namespace std;
int main(){
    int *p=new int;
    *p=10;
    cout<<*p<<endl;

    double *pd=new double;

    char *c=new char;

    //allocating an array in heap memory
    //syntax- int*p= new int[50] (we stored in an int pointer because it gives address of 0th element)
    int *pa= new int [50]; //total memory allocated here- 200 in heap and 8 in stack

    int n;
    cout<<"enter the number of elements"<<endl;
    cin>>n;

    int*pa2=new int[n]; //valid ab; no error
    //pa2 works exactly like arrays
    //pa2[0]=10;
    for(int i=0;i<n;n++){
        cin>>pa2[i];
    }
    int max=-1;
    for(int i=0;i<n;i++){
        if(max<pa2[i]){
            max=pa2[i];
        }
    }
    cout<<max<<endl;
}