class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
private:
    int depth(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }
        int l = depth(root -> left, diameter), r = depth(root -> right, diameter);
        diameter = max(diameter, l + r);
        return max(l, r) + 1;
    }
};
