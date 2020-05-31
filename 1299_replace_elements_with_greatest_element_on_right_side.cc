#include <vector>
#include <iostream>

using namespace std;

/*
1299. Replace Elements with Greatest Element on Right Side
Easy

Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]

 

Constraints:

    1 <= arr.length <= 10^4
    1 <= arr[i] <= 10^5
*/

/*
Success
Details
Runtime: 1312 ms, faster than 5.02% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
Memory Usage: 15.2 MB, less than 100.00% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
*/
vector<int> replaceElements(vector<int>& arr) {
    vector<int> v = {};
    
    
    for(int i = 0; i < arr.size(); i++) {
        if(i == arr.size() - 1)
            v.push_back(-1);
        else {
            int max = 0;
            for(int j = i+1; j < arr.size(); j++) {
                if(arr[j] > max)
                    max = arr[j];
            }

            v.push_back(max);
        }
    }
    return v;
}

/*
TODO
*/
vector<int> replaceElementsAlt(vector<int>& arr)  {
	return arr;
}

int main(int argc, char** argv) {
	vector<int> arr = {17,18,5,4,6,1};
	vector<int> v = replaceElements(arr);
	for(auto e : v)
		cout << e << ' ';
	cout << endl;
}