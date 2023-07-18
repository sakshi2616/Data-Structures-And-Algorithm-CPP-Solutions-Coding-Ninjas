#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    string input;
	    cin>>input;
	    if(n%2!=0){
	        cout<<"NO"<<endl;
	        
	    }
	    else{
	        bool check=true;
	        for(int j=0;j<input.size();j++){
	            int count=0;
	            for(int k=0;k<input.size();k++){
	                if(input[k]==input[j] && k!=j){
	                    count++;
	                }
	            }
	            if(count%2==0){
	                cout<<"NO"<<endl;
	                check=false;
	                break;
	            }
	            
	        }
	        if(check){
	            cout<<"YES"<<endl;
	        }
	    }
	}
	return 0;
}
