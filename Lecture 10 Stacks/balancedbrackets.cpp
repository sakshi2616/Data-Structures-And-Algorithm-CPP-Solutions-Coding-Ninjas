#include<bits/stdc++.h>
using namespace std;

#include <stack>
int main(){
    string question;
    cin>>question;
    stack<char> answer;
    for(int i=0;i<question.length();i++){
        if(answer.empty()){
            answer.push(question[i]);
        }
        else if ((answer.top() == '(' && question[i] == ')') || (answer.top() == '{' && question[i] == '}') || (answer.top() == '[' && question[i] == ']')){
            answer.pop();
        }
        else{
            answer.push(question[i]);
        }
    }

    if(answer.empty()){
        cout<<"true";
    }
    else{
        cout<<"False";
    }
}