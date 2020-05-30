#include <iostream>
#include <vector>

using namespace std;

/*
728. Self Dividing Numbers
Easy

A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:

Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

Note:
The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

bool is_self_dividing(int n) {
    int num = n;
    while(num > 0) {

        if(num % 10 == 0)
            return false;
        
        if((n % (num % 10)) != 0) 
            return false;
        
        num /= 10;
    }
    return true;
}

/*
Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Self Dividing Numbers.
Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Self Dividing Numbers.
*/
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> v = {};
    
    if(left < 1)
        while(left < 1)
            left++;
    
    for(int i = left; i <= right; i++)
        if(is_self_dividing(i))
            v.push_back(i);

    return v;
}

int main(int argc, char** argv) {
    vector<int> v = selfDividingNumbers(1,22);

    for(auto e : v)
        cout << e << ' ';
    cout << endl;
    return 0;
}