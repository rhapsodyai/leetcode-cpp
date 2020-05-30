#include <stdio.h>
#include <iostream>

using namespace std;

int getSum(int a, int b) {
    while(b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
        
        cout << "a " << a << endl;
        cout << "b " << b << endl;
        cout << "carry " << carry << endl;
    }
    return a;
}

int main(int argc, char** argv) {
    cout << getSum(1,2);
}
