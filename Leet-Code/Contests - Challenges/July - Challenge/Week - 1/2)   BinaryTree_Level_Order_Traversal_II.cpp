class Solution {
public:
    void recurFunc(TreeNode* node, int depth, vector<vector<int>>& answer)
    {
        for (auto i = answer.size(); i <= depth; ++i)
        {
            vector<int> emptyVec;
            answer.push_back(emptyVec);
        }
        answer[depth].push_back(node->val);
        
        if (node->left)
            recurFunc(node->left, depth+1, answer);
        if (node->right)
            recurFunc(node->right, depth+1, answer);
        
        return;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;

        if (root)
        {
            recurFunc(root, 0, ret);
            reverse(ret.begin(), ret.end());
        }
        return ret;
    }
};
