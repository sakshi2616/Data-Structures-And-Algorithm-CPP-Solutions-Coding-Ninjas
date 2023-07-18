#include<bits/stdc++.h>
using namespace std;
#include "priority_queue.h"

int main(){
    priorityqueue p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getsize()<<endl;
    cout<<p.getmin()<<endl;

    while(!p.isempty()){
        cout<<p.removemin()<<" ";
    }
}