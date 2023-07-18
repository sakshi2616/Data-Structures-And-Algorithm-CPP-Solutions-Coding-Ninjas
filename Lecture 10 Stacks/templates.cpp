#include<bits/stdc++.h>
using namespace std;

template <typename T, typename V>
//object create krte hue specify krna hoga what we want as T

class pairs{
    T x;
    V y;

    public:

    void setx(T x){
        this->x=x;
    }

    T getx(){
        return x;
    }

    void sety(V y){
        this->y=y;
    }

    V gety(){
        return y;
    }

};