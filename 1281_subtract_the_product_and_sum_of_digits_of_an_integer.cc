#include <stdio.h>
#include <iostream>

using namespace std;


/*
Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
*/
int subtractProductAndSum(int n) {
    int product = 1;
    int sum = {};
    
    while(n >  0) {
        sum += n % 10;
        product *= n % 10;
        n /= 10;
    }
    
    return product-sum;
}


int main(int argc, char** argv) {
	cout << subtractProductAndSum(234) << endl;
}