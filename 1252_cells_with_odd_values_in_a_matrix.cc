#include <iostream>
#include <vector>

using namespace std;

/*
Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

Return the number of cells with odd values in the matrix after applying the increment to all indices.

Example 1:

Input: n = 2, m = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.

Example 2:

Input: n = 2, m = 2, indices = [[1,1],[0,0]]
Output: 0
Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.

Constraints:

    1 <= n <= 50
    1 <= m <= 50
    1 <= indices.length <= 100
    0 <= indices[i][0] < n
    0 <= indices[i][1] < m
*/

void print_vector(vector<vector<int>> v) {
    for(auto e : v) {
        for(auto el : e) {
            cout << el;
        }
        cout << endl;
    }
}

void increment_column(vector<vector<int>>& v, int c, int n) {
    for(int j = 0; j < n; j++) {
        v[j][c]++;
    }
}

void increment_row(vector<vector<int>>& v, int r, int m) {
    for(int i = 0; i < m; i++) {
        v[r][i]++;
    }
}

/*
Success
Details
Runtime: 8 ms, faster than 45.84% of C++ online submissions for Cells with Odd Values in a Matrix.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Cells with Odd Values in a Matrix.
*/
int oddCells(int n, int m, vector<vector<int>>& indices) {
    // initialize zero fill m x n vector
    vector<vector<int>> v = {};
    for(int i = 0; i < n; i++) {
        vector<int> t = {};
        for(int j = 0; j < m; j++) {
            t.push_back(0);
        }
        v.push_back(t);
    }
    
    // increment the rows and columns
    for(auto e : indices) {
        increment_row(v, e[0], m);
        increment_column(v, e[1], n);
    }
    
    // count the odd numbers in the final vector
    int c = {};
    for(auto e : v)
        for(auto el : e)
            if(el % 2 == 1)
                c++;
    
    return c;
}

int main(int argc, char** argv) {
	vector<vector<int>> v = {{0,1},{1,1}};
	cout << oddCells(2, 3, v) << endl;
}