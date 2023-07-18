#include <iostream>
using namespace std;

void updateValue(int *p){
    *p = 610 % 255;
}

int main(){
    char ch = 'A';
    updateValue((int*)&ch);
    cout << ch;

    /*p is also having the address of ch

so *p will point towards the value of ch and try to read the 4 bits as

it will read it as an integer so it will read 65+ garbage value

and when *p =610%255

the remainder of the above equation will be 100

*p-value is now reassigned to 100

When we print the ch it will convert it into ASCII value form

Then it will print the value corresponding to 100

that is 'd' */
}