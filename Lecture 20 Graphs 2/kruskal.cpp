#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(edge e1,edge e2){
    return e1.weight<e2.weight;
} 

int findparent(int v, int *parent){
    if(v==parent[v]){
        return v;
    }
    return findparent(parent[v],parent);
}

void kruskal(edge*input, int n, int e){
    //sort the input array
    sort(input, input+e,compare);

    edge*output=new edge[n-1];

    int *parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int count=0;
    int i=0;
    while(count<n-1){
        edge current=input[i];

        //check if we can add current edge in mst or not
        int sourceparent=findparent(current.source,parent);
        int destparent=findparent(current.dest,parent);

        if(sourceparent!=destparent){
            output[count]=current;
            count++;
            parent[sourceparent]=destparent;
        }
        i++;

    }

    for(int i=0;i<n;i++){
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    edge *input=new edge[e];

    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;

        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }

    kruskal(input,n,e);
}
