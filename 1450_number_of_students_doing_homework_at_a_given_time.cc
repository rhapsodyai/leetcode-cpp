#include <vector>
#include <iostream>

using namespace std;

/*
1450. Number of Students Doing Homework at a Given Time
Easy

Given two integer arrays startTime and endTime and given an integer queryTime.

The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].

Return the number of students doing their homework at time queryTime. More formally, return the number of students where queryTime lays in the interval [startTime[i], endTime[i]] inclusive.

 

Example 1:

Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
Output: 1
Explanation: We have 3 students where:
The first student started doing homework at time 1 and finished at time 3 and wasn't doing anything at time 4.
The second student started doing homework at time 2 and finished at time 2 and also wasn't doing anything at time 4.
The third student started doing homework at time 3 and finished at time 7 and was the only student doing homework at time 4.

Example 2:

Input: startTime = [4], endTime = [4], queryTime = 4
Output: 1
Explanation: The only student was doing their homework at the queryTime.

Example 3:

Input: startTime = [4], endTime = [4], queryTime = 5
Output: 0

Example 4:

Input: startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
Output: 0

Example 5:

Input: startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
Output: 5

 

Constraints:

    startTime.length == endTime.length
    1 <= startTime.length <= 100
    1 <= startTime[i] <= endTime[i] <= 1000
    1 <= queryTime <= 1000
*/
bool inBetween(int l, int h, int n) {
    if(n >= l && n <= h)
        return true;
    else
        return false;
}

/*
Success
Details
Runtime: 8 ms, faster than 67.28% of C++ online submissions for Number of Students Doing Homework at a Given Time.
Memory Usage: 11 MB, less than 100.00% of C++ online submissions for Number of Students Doing Homework at a Given Time.
*/
int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int count = {};
    for(int i = 0; i < startTime.size(); i++) {
        if(inBetween(startTime[i],endTime[i],queryTime))
            count++;
    }
    return count;
}

int main(int argc, char** argv) {
    vector<int> v_start{1,2,3};
    vector<int> v_end{3,2,7};
    int qt = 4;

    cout << busyStudent(v_start, v_end, qt) << endl;
}

