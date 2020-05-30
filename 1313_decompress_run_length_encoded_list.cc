#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int> decompressRLElist(vector<int>& nums) {
    /*
    Runtime: 4 ms, faster than 99.56% of C++ online submissions for Decompress Run-Length Encoded List.
    Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Decompress Run-Length Encoded List.
    */
    vector<int> v = {};
    for(int i = 0; i < nums.size()-1; i+=2) {
        for(int j = 0; j < nums[i]; j++) {
            v.push_back(nums[i+1]);
        }
    }

    return v;

    /*
    Runtime: 8 ms, faster than 95.68% of C++ online submissions for Decompress Run-Length Encoded List.
    Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Decompress Run-Length Encoded List.

    vector<int> v = {};
    for(int i = 0; i<nums.size(); i=i+2)
        while(nums[i]--)
            v.push_back(nums[i+1]);
    return v;
    */
}

int main(int argc, char** argv) {
    vector<int> v = {1,2,3,4};
    vector<int> v2 = decompressRLElist(v);

    for(auto e : v2)
        cout << e << ' ';

    cout << endl;
}



