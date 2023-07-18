#include<bits/stdc++.h>
using namespace std;

priority_queue<int> ksmall(int input[], int n, int k){
    priority_queue<int> small;
    //making max heap
    for(int i=0;i<k;i++){
        small.push(input[i]);
    }

    for(int i=k;i<n;i++){
        int temp=small.top();
        if(input[i]<temp){
            small.pop();
            small.push(input[i]);
        }
    }
    return small;
}

int main(){
    //inbuilt priority queue is max heap
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int k;
    cin>>k;

    priority_queue<int> output=ksmall(input,n,k);
    while(!output.empty()){
        cout<<output.top()<<" ";
        output.pop();
    }
    cout<<endl;
}