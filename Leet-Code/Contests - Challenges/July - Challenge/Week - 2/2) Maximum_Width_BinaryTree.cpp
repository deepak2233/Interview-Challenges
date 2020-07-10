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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        deque<TreeNode*> q[2];
        bool input=true;
        q[input].push_front(root);
        input=false;
        int max_width=1;
        while(q[!input].size()){
            TreeNode* temp=q[!input].back();q[!input].pop_back();
            if(!temp){
                q[input].push_front(nullptr);
                q[input].push_front(nullptr);
                continue;
            }else{
                q[input].push_front(temp->left);
                q[input].push_front(temp->right);
            }
            if(q[!input].empty()){
                while(q[input].size()&&q[input].front()==NULL)q[input].pop_front();
                while(q[input].size()&&q[input].back()==NULL)q[input].pop_back();
                max_width=max(max_width,(int)q[input].size());
                input=!input;
            }
		}
        return max_width;
    }
};
