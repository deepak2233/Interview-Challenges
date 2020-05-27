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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        vector<int> values;
        inorder(root, values, k, 0);
        return values[k-1];
    }
    
    void inorder(TreeNode *root, vector<int>& values, int k, int count) {
        // static int count = 0;
        if (root) {
            inorder(root->left, values, k, count);
            count +=1;
            values.push_back(root->val);
            if (count >= k) return;
            inorder(root->right, values, k, count);
        }
    }
};
