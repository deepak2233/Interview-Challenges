class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(root == nullptr)
            return false;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({nullptr, root});
        
        while(!q.empty())
        {
            int size = q.size();
            int flag = 2;
            TreeNode* parents[2] = {nullptr, nullptr};
            
            for(int i=0; i<size; i++)
            {
                auto n = q.front();
                q.pop();

                if(n.first && (n.second->val == x || n.second->val == y))
                {
                    parents[2-flag] = n.first;
                    flag--;
                }

                if(n.second->left) q.push({n.second, n.second->left});
                if(n.second->right) q.push({n.second, n.second->right});
            }
            
            if(flag == 1)
                return false;
            else if(flag == 0)
                return (parents[0] != parents[1]);
        }
        
        return false;
    }
};
