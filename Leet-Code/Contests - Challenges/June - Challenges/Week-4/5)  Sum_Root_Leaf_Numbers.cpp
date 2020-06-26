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
    int sumNumbers(TreeNode* root, int x = 0) {
        if (!root) return 0;
        if (!root->left && !root->right) return 10 * x + root->val;
        return sumNumbers(root->left, 10 * x + root->val) + sumNumbers(root->right, 10 * x + root->val);
    }
};
