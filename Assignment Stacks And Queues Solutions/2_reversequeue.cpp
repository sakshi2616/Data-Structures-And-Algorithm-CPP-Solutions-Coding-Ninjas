#include<bits/stdc++.h>
using namespace std;
#include<queue>

void reversequeue(queue <int>& q){
    if(q.empty()){
        return;
    }
    int data=q.front();
    q.pop();
    reversequeue(q);
    q.push(data);
}

int main(){
    queue<int> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int z;
        cin>>z;
        q.push(z);
    }

    reversequeue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    

}