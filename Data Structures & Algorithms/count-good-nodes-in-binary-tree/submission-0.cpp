/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* node, int maxValue) {
        if (node == NULL)
            return 0;

        int good = 0;

        if (node->val >= maxValue) {
            good = 1;
            maxValue = node->val;
        }

        good += solve(node->left, maxValue);
        good += solve(node->right, maxValue);

        return good;
    }

    int goodNodes(TreeNode* root) {
        return solve(root, INT_MIN);
    }
};
