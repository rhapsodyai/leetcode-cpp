#include <iostream>
#include <vector>

using namespace std;

/*
1351. Count Negative Numbers in a Sorted Matrix
Easy

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3

Example 4:

Input: grid = [[-1]]
Output: 1

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

*/


/*
Success
Details
Runtime: 24 ms, faster than 59.80% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 10.7 MB, less than 100.00% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
*/
int countNegatives(vector< vector<int> >& grid) {
    int sum = {};
    int cumm = {};
    
    for(int i = grid.size()-1; i >= 0; i--) {
        for(int j = grid[0].size()-1; j >= 0; j--) {
            if(grid[i][j] < 0) {
                sum++;
                cumm++;
            }
        }
        
        if(cumm == 0)
            break;
        else
            cumm = 0;
    }
    return sum;
}

int main(int argc, char** argv) {
    vector< vector<int> > v = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout << countNegatives(v) << endl;
}
