#include<bits/stdc++.h>
using namespace std;
#include<stack>

int main(){
    stack <int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }

    stack<int> answer;
    int q;
    for(int i=0;i<n;i++){
        q=s.top();
        s.pop();
        answer.push(q);
    }

    while(!answer.empty()){
        cout<<answer.top()<<" ";
        answer.pop();
    }
    cout<<endl;
}