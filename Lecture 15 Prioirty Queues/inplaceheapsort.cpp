#include<bits/stdc++.h>
using namespace std;

void inplaceheapsort(int input[], int n){
    //build the heap inside the array
    for(int i=1;i<n;i++){
        int childindex=i;

        while(childindex>0){
        int parentindex=(childindex-1)/2;

        if(input[childindex]<input[parentindex]){
            int temp=input[childindex];
            input[childindex]=input[parentindex];
            input[parentindex]=temp;
        }
        else{
            break;
        }
        childindex=parentindex;  
        }
    }


    //remove elements
    int size=n;
    while(size>1){
    int temp=input[0];
    input[0]=input[size-1];
    input[size-1]=temp;
    size--;

    int parentindex=0;
    int leftindex=(2*parentindex)+1;
    int rightindex=(2*parentindex)+2;
        
        while(leftindex<size){
            
            int minindex=parentindex;
            if(input[minindex]>input[leftindex]){
                minindex=leftindex;
            }
            if(input[minindex]>input[rightindex] && rightindex<size){
                minindex=rightindex;
            }

            if(parentindex==minindex){
                break;
            }

            int temp=input[minindex];
            input[minindex]=input[parentindex];
            input[parentindex]=temp;
 
            parentindex=minindex;
            leftindex=(2*parentindex)+1;
            rightindex=(2*parentindex)+2;
        }

    }

}

int main(){
    int input[]={5,1,2,0,8};
    inplaceheapsort(input,5);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
}