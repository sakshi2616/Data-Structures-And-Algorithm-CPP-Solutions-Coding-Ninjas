#include <iostream>
using namespace std;

#define SQUARE(x) x*x

int main(){
    int x = 36 / SQUARE(6);
    cout << x;

    return 0;
}

/* Preprocessor replaces square(6) by 6*6 and the expression becomes 
x = 36/6*6 and value of x is calculated as 36.  */