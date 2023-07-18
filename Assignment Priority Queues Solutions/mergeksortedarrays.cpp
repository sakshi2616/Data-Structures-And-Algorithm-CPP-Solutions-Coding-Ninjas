#include<bits/stdc++.h>
using namespace std;

/*class triplet{
    public:
    int ele;
    int ai;
    int ei;
    
    triplet(int a,int b,int c){
        this->ele=a;
        this->ai=b;
        this->ei=c;
    }
};

vector<int> mergek(vector<vector<int>> s, int k){
    vector<int> output;
    priority_queue<triplet,vector<triplet>,greater<triplet>> pq;
    //int c=0;
    for(int i=0;i<s.size();i++){
        int x=s[i][0];
        triplet temp(x,i,0);
        pq.push(temp);
    }
    
    while(!pq.empty()){
    triplet sak=pq.top();
    int x=sak.ele;
    int y=sak.ai;
    int z=sak.ei;
    output.push_back(x);
    pq.pop();
    if((s[y].size()-1)!=z){
        int p=s[y][z+1];
        
        triplet temp(p,y,z+1);
        pq.push(temp);
    }
    }
    return output;
}*/

vector<int> mergeKSortedArrays(vector<vector<int>> input){
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    
    for(int i=0;i<input.size();i++){
        vector<int>current=input[i];
        for(int j=0;j<current.size();j++){
            
            pq.push(current[j]);
        }
    }
    
    vector<int> ans;
    int size=pq.size();
    for(int i=0;i<size;i++){
        
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
    
}

int main(){
    int k;
    cin>>k;
    vector<vector<int>> s;
    for(int i=0;i<k;i++){
        vector<int> temp;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        s.push_back(temp);
    }
    

    vector<int> output=mergeKSortedArrays(s);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
}