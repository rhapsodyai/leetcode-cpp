#include <iostream>
#include <vector>

using namespace std;

/*
1295. Find Numbers with Even Number of Digits
Easy
Given an array nums of integers, return how many of them contain an even number of digits.

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits. 

Constraints:

    1 <= nums.length <= 500
    1 <= nums[i] <= 10^5
*/

bool digits_even(int n) {
    int count = {};
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count % 2 == 0;
}

/*
Runtime: 12 ms, faster than 44.85% of C++ online submissions for Find Numbers with Even Number of Digits.
Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Find Numbers with Even Number of Digits.
*/
int findNumbers(vector<int>& nums) {
    int total_even = {};
    for(auto& e : nums)
        total_even += digits_even(e);

    return total_even;
}

int main(int argc, char** argv) {
	vector<int> v = {12,345,2,6,7896};
	cout << findNumbers(v) << endl;
}
