#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
1403. Minimum Subsequence in Non-Increasing Order
Easy

Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.

Example 1:

Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements. 

Example 2:

Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order.  

Example 3:

Input: nums = [6]
Output: [6]


Constraints:

    1 <= nums.length <= 500
    1 <= nums[i] <= 100
*/

/*
Success
Details
Runtime: 16 ms, faster than 79.62% of C++ online submissions for Minimum Subsequence in Non-Increasing Order.
Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Minimum Subsequence in Non-Increasing Order.
*/
vector<int> minSubsequence(vector<int>& nums) {
    // sort array in descending order
    sort(nums.begin(), nums.end(), greater<int>());
    
    // get sum of all elements
    int sum = {};
    for(auto e : nums)
        sum += e;
    
    // get mid point
    int mid = {};
    int count = {};
    for(auto e : nums) {
        if(mid <= sum/2) {
            mid += e;
            count++;
        } else {
            break;
        }
    }
    
    // shorten vector to the first n elements
    nums.resize(count);
    
    return nums;
}

int main(int argc, char** argv) {
    vector<int> v = {4,3,10,9,8};
    minSubsequence(v);
    for(auto e : v)
        cout << e << ' ';
    cout << endl;
}