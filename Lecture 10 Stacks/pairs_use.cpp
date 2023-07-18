#include<bits/stdc++.h>
using namespace std;
#include"templates.cpp"

int main(){
    pairs<int, double> p1;
    p1.setx(8);
    p1.sety(5.689);
    
    //cout<<p1.getx()<<" "<<p1.gety()<<endl;

    pairs<double, int> p2;
    p2.setx(100.34);
    p2.sety(34.21);

    //cout<<p2.getx()<<" "<<p2.gety()<<endl;

    pairs<char, int> p3;

    //TRIPLET CLASS USING PAIRS CLASS: pairs<pairs<int,int>, int> p2;
    pairs<pairs<int,int>,int> p4;
    p4.sety(10);
    pairs<int,int> p5;
    p5.setx(5);
    p5.sety(16);
    p4.setx(p5); //COPY ASSIGNMENT OPERATOR USED

    cout<<p4.getx().getx()<<" "<<p4.getx().gety()<<" "<<p4.gety()<<endl;
    //triplet with one int, one double , one char-> pair<int, pair<double,char>> pnew
}
