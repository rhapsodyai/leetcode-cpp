#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    /*
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Create Target Array in the Given Order.
    Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Create Target Array in the Given Order.
    */
    vector<int> v = {};

    for(int i = 0; i < nums.size(); i++) 
        v.insert(v.begin() + index[i], nums[i]);

    return v;
}

int main(int argc, char** argv) {
    vector<int> v1 = {0,1,2,3,4};
    vector<int> v2 = {0,1,2,2,1};
    vector<int> v = createTargetArray(v1, v2);

   for(auto e : v)
        cout << e << ' ';

    cout << endl;
}
