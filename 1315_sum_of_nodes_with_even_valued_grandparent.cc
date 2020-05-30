#include <vector>
#include <iostream>

using namespace std;

/*
1315. Sum of Nodes with Even-Valued Grandparent
Medium

Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.


Example 1:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.


Constraints:

    The number of nodes in the tree is between 1 and 10^4.
    The value of nodes is between 1 and 100.

*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> v = {};
int sum = {};

/*
Success
Details
Runtime: 104 ms, faster than 6.51% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
Memory Usage: 38.4 MB, less than 100.00% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
*/
int sumEvenGrandparent(TreeNode* root) {

    if(v.size() >= 2)
        if(v[v.size()-2]->val % 2 == 0)
            sum += root->val;
    
    if(root->left) {
        v.push_back(root);
        sumEvenGrandparent(root->left);
    }
    
    if(root->right) {
        v.push_back(root);
        sumEvenGrandparent(root->right);
    }
    
    v.pop_back();
    return sum;
}

int main(int argc, char** argv) {
    TreeNode* n11 = new TreeNode(5, nullptr, nullptr);
    TreeNode* n10 = new TreeNode(3, nullptr, n11);
    TreeNode* n9 = new TreeNode(1, nullptr, nullptr);
    TreeNode* n8 = new TreeNode(8, n9, n10);
    TreeNode* n7 = new TreeNode(4, nullptr, nullptr);
    TreeNode* n6 = new TreeNode(1, nullptr, nullptr);
    TreeNode* n5 = new TreeNode(7, n6, n7);
    TreeNode* n4 = new TreeNode(9, nullptr, nullptr);
    TreeNode* n3 = new TreeNode(2, n4, nullptr);
    TreeNode* n2 = new TreeNode(7, n3, n5);
    TreeNode* n1 = new TreeNode(6, n2, n8);
    
    cout << sumEvenGrandparent(n1) << endl;
}