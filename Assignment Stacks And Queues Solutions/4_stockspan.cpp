#include<bits/stdc++.h>
using namespace std;
#include<stack>

int main(){
    int n;
    cin>>n;

    int answer[n];
    answer[0]=1;

    int question[n];
    for(int i=0;i<n;i++){
        cin>>question[i];
    }

    stack<int> s;
    s.push(0);
    
    for(int i=1;i<n;i++){
        if(question[i]>question[s.top()]){
            int count=0;
            while(!s.empty() && question[s.top()]<question[i]){
                s.pop();
                count++;
            }

            if(s.empty()){
                answer[i]=i+1;
                s.push(i);
            }
            else{
                answer[i]=count+1;
                s.push(i);
            }
            count=0;

        }
        else{
            answer[i]=1;
            s.push(i);
        }
    }

    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }

}