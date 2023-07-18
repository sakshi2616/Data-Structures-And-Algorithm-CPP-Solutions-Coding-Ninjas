#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> ourmap;

    //inseting elements in map
    pair<string,int> p("abc",1);
    ourmap.insert(p);

    ourmap["def"]=2;

    //find or access elements
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;

    //cout<<ourmap.at("ghi")<<endl; (error)
    cout<<"size:"<<ourmap.size()<<endl;
    cout<<ourmap["ghi"]<<endl; //yeh dekhta hai ki nahi hai to default value 0 insert krdeta is key ke lie 
    //squre brackets sochke use krna
    cout<<"size:"<<ourmap.size()<<endl;
    //use:
    //check presense
    //count ya to 0 hogi ya 1 (ek key ek baar hi ho skti)
    if(ourmap.count("ghi")>0){
        cout<<"ghi exists"<<endl;
    }

    //erase
    ourmap.erase("ghi");
    cout<<"size:"<<ourmap.size()<<endl;
    if(ourmap.count("ghi")>0){
        cout<<"ghi exists"<<endl;
    }



}
