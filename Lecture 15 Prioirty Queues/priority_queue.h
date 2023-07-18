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

    int getmin(){
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

        if(pq[childindex]<pq[parentindex]){
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
            
            int minindex=parentindex;
            if(pq[minindex]>pq[leftindex]){
                minindex=leftindex;
            }
            if(pq[minindex]>pq[rightindex] && rightindex<pq.size()){
                minindex=rightindex;
            }

            if(parentindex==minindex){
                break;
            }

            int temp=pq[minindex];
            pq[minindex]=pq[parentindex];
            pq[parentindex]=temp;
 
            parentindex=minindex;
            leftindex=(2*parentindex)+1;
            rightindex=(2*parentindex)+2;
        }

        return ans;
    }
};