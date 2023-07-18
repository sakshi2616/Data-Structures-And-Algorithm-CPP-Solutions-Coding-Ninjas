#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v; //statically
    vector<int>*v2=new vector<int>(); //dynamically

    //insert->pushback;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v[1]=100;

    //v[3]=10002; aisa krenge to woh size increase nahi krega

    //v[3]=3;
    //v[4]=4;
    //so we will not use [] like this
    v.push_back(40);
    v.push_back(50);

    //we will use [] to acces elements, and updates (not for inserting)

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;

    //alternate for []

    cout<<v.at(2)<<endl;
    cout<<v.at(3)<<endl;
    //v.at(8) will give error because itne elements to push back hi nahi kre

    cout<<v.size()<<endl;

    //printing all elements

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    //removing last element
    v.pop_back();

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    //capacity->tells current capacity
    //v.capacity()

    
}