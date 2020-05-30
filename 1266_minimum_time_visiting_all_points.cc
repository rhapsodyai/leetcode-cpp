#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

/*
1266. Minimum Time Visiting All Points
Easy

On a plane there are n points with integer coordinates points[i] = [xi, yi]. Your task is to find the minimum time in seconds to visit all points.

You can move according to the next rules:

    In one second always you can either move vertically, horizontally by one unit or diagonally (it means to move one unit vertically and one unit horizontally in one second).
    You have to visit the points in the same order as they appear in the array.

 

Example 1:

Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds

Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5

 

Constraints:

    points.length == n
    1 <= n <= 100
    points[i].length == 2
    -1000 <= points[i][0], points[i][1] <= 1000
*/
int calculateShortestDistance(int x1, int y1, int x2, int y2) {
    int arr[2] = {abs(x2-x1), abs(y2-y1)};

    if(arr[0] > arr[1])
        return arr[0];

    return arr[1];
}

/*
Success
Details
Runtime: 12 ms, faster than 63.85% of C++ online submissions for Minimum Time Visiting All Points.
Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Minimum Time Visiting All Points.
*/
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    bool first = false;
    int sum = {};
    int last_x = {};
    int last_y = {};

    for(auto& e : points) {
        if(first)
            sum += calculateShortestDistance(e[0], e[1], last_x, last_y);
        else
            first = true;
        last_x = e[0];
        last_y = e[1];
    }

    return sum;
}

int main(int argc, char** argv) {
	vector<int> v1 = {1,1};
	vector<int> v2 = {3,4};
	vector<int> v3 = {-1,0};

	vector<vector<int>> v = {};
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	cout << minTimeToVisitAllPoints(v) << endl;
}