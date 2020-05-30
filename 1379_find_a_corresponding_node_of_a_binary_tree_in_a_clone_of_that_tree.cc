#include <cstddef>
#include <iostream>

using namespace std;
/*
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
Medium

Given two binary trees original and cloned and given a reference to a node target in the original tree.
The cloned tree is a copy of the original tree.
Return a reference to the same node in the cloned tree.
Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.
Follow up: Solve the problem if repeated values on the tree are allowed.
 
Example 1:
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

Example 2:
Input: tree = [7], target =  7
Output: 7

Example 3:
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4

Example 4:
Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
Output: 5

Example 5:
Input: tree = [1,2,null,3], target = 2
Output: 2

Constraints:

    The number of nodes in the tree is in the range [1, 10^4].
    The values of the nodes of the tree are unique.
    target node is a node from the original tree and is not null.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
Success
Details
Runtime: 1108 ms, faster than 8.02% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
Memory Usage: 164.5 MB, less than 100.00% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
*/
TreeNode* ans = {};
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

    int val = target->val;

    if(cloned->val == val)
        ans = cloned;

    if(cloned->left)
        getTargetCopy(original, cloned->left, target);
    if(cloned->right)
        getTargetCopy(original, cloned->right, target);

    return ans;
}

/*
--- From Discussion - zhaoyaqiong ---
Runtime: 1220 ms, faster than 6.09% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
Memory Usage: 164.3 MB, less than 100.00% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
*/
TreeNode* getTargetCopyAlt(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    TreeNode* result = NULL;
    
    if(original == NULL)
        return result;

    if(target->val == cloned->val)
        return cloned;
    else {
        result = getTargetCopy(original->left, cloned->left, target);

        if(result)
            return result;

        result = getTargetCopy(original->right, cloned->right, target);
        return result;
    }
}

int main(int argc, char** argv) {
    TreeNode* n5 = new TreeNode(19);
    TreeNode* n4 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n1 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    TreeNode* n5_clone = new TreeNode(19);
    TreeNode* n4_clone = new TreeNode(6);
    TreeNode* n3_clone = new TreeNode(3);
    TreeNode* n2_clone = new TreeNode(4);
    TreeNode* n1_clone = new TreeNode(7);

    n1_clone->left = n2;
    n1_clone->right = n3;
    n3_clone->left = n4;
    n3_clone->right = n5;

    TreeNode* t = new TreeNode(3);

    cout << getTargetCopy(n1, n1_clone, t)->val << endl;
}

