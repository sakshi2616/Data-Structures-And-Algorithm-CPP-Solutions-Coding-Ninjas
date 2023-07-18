#include<bits/stdc++.h>
using namespace std;

/*void running(int n, int input[]){
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int j=0;j<n;j++){
        for(int h=0;h<=j;h++){
        pq.push(input[h]);
        }
        int s=pq.size();
        if(s%2!=0){
            int t=s/2;
            for(int k=0;k<t;k++){
                pq.pop();
            }
            cout<<pq.top()<<endl;
        }
        
        else{
            int t=s/2;
            int u=t-1;
            for(int k=0;k<u;k++){
                pq.pop();
            }
            int q=pq.top();
            pq.pop();
            int r=pq.top();
            cout<<(q+r)/2<<endl;
        }
        while(!pq.empty()){
            pq.pop();
        }

    }
}*/ //brute force

//optimised

bool check(priority_queue<int> max, priority_queue<int, vector<int>, greater<int>> min){
    if(abs(max.size()-min.size())>1){
        return true;
    }
    return false;
}

void running(int n, int input[]){
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    mx.push(input[0]);
    cout<<mx.top()<<endl;
    for(int j=1;j<n;j++){
        if(input[j]>mx.top()){
            mn.push(input[j]);
        }
        else{
        mx.push(input[j]);
        }
        while(check(mx,mn)){
            if(mx.size()>mn.size()){
            int temp=mx.top();
            mx.pop();
            mn.push(temp);
            }
            else{
                int temp=mn.top();
                mn.pop();
                mx.push(temp);
            }
        }
        if(mn.size()==0){
            cout<<mx.top()<<endl;
        }
        else if(mn.size()==mx.size()){
            cout<<(mx.top()+mn.top())/2<<endl;
        }
        else if(mx.size()>mn.size()){
            cout<<mx.top()<<endl;
        }
        else if(mn.size()>mx.size()){
            cout<<mn.top()<<endl;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];

    }

    running(n,input);

}