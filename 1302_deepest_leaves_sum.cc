#include <stdio.h>

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

bool heightComputed = false;
int sum = {};
int depth = {};
int max_depth = {};

// first traverse the tree to get the height
int computeHeight(TreeNode* n, int depth) {
    if(n->left)
        computeHeight(n->left, depth+1);

    if(n->right)
        computeHeight(n->right, depth+1);

    if(depth > max_depth)
        max_depth = depth;

    depth--;
    return max_depth;
}

/*
Success
Details
Runtime: 68 ms, faster than 18.27% of C++ online submissions for Deepest Leaves Sum.
Memory Usage: 38.4 MB, less than 100.00% of C++ online submissions for Deepest Leaves Sum.
*/
int deepestLeavesSum(TreeNode* root) {

    // if height not computed yet, computer height
    if(!heightComputed) {
        computeHeight(root, 0);
        heightComputed = true;
    }

    // traverse tree while comparing nodes to max height
    if(root->left) {
        depth++;
        deepestLeavesSum(root->left);
    }

    if(root->right) {
        depth++;
        deepestLeavesSum(root->right);
    }

    if(depth == max_depth)
        sum += root->val;
    depth--;


    return sum;
}

int main(int argc, char** argv) {
    TreeNode* n = {};
    deepestLeavesSum(n);
    return 0;
}