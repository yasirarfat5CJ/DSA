TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* predecessor = nullptr;

    while (root) {
        if (p->val > root->val) {
            // Possible predecessor, go right to find closer one
            predecessor = root;
            root = root->right;
        } 
        else {
            // Go left if current node is >= p
            root = root->left;
        }
    }

    return predecessor;
}
