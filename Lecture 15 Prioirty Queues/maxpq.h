#include<bits/stdc++.h>
using namespace std;

class priorityqueue{
    vector<int> pq;

    public:
    priorityqueue(){

    }

    bool isempty(){
        return pq.size()==0;
    }

    //return the size of priority queue
    int getsize(){
        return pq.size();
    }

    int getmax(){
        if(isempty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);
        int childindex=pq.size()-1;

        while(childindex>0){
        int parentindex=(childindex-1)/2;

        if(pq[childindex]>pq[parentindex]){
            int temp=pq[childindex];
            pq[childindex]=pq[parentindex];
            pq[parentindex]=temp;
        }
        else{
            break;
        }
        childindex=parentindex;
        
        }
    }

    int removemin(){
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        int parentindex=0;
        int leftindex=(2*parentindex)+1;
        int rightindex=(2*parentindex)+2;
        
        while(leftindex<pq.size()){
            
            int maxindex=parentindex;
            if(pq[leftindex]>pq[maxindex]){
                maxindex=leftindex;
            }
            if(pq[rightindex]>pq[maxindex] && rightindex<pq.size()){
                maxindex=rightindex;
            }

            if(parentindex==maxindex){
                break;
            }

            int temp=pq[maxindex];
            pq[maxindex]=pq[parentindex];
            pq[parentindex]=temp;
 
            parentindex=maxindex;
            leftindex=(2*parentindex)+1;
            rightindex=(2*parentindex)+2;
        }

        return ans;
    }
};