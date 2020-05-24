class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder.begin(), preorder.end());
    }
    
    TreeNode * helper(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end) {
            return nullptr;
        }
        
        auto node = new TreeNode(*begin);
        auto right = upper_bound(begin + 1, end, *begin);
        
        node->left = helper(begin + 1, right);
        node->right = helper(right, end);
        return node;
    }
};
