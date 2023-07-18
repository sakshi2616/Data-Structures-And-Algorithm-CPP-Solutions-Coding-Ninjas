#include<bits/stdc++.h>
using namespace std;

int ticket(int n, int input[], int k){
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(input[i]);
    }

    int time=0;
    while(!q.empty()){
        if(input[q.front()]==pq.top() && q.front()==k){
            pq.pop();
            q.pop();
            time++;
            break;
        }
        else if(input[q.front()]==pq.top()){
            pq.pop();
            q.pop();
            time++;
        }
        else{
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
    }

    return time;

}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    int k;
    cin>>k;

    int time=ticket(n,input,k);
    cout<<time<<endl;
}