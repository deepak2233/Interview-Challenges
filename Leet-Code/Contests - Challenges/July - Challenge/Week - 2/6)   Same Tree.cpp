bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p || !q) return q == p;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
