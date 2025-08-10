TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* predecessor = nullptr;

    while (root) {
        if (p->val > root->val) {
            
            inorderSuccessor = root;
            root = root->right;
        } 
        else {
            
            inorderSuccessor = root;
            root = root->left;
        }
    }

    return inorderSuccessor;
}
/* Inorder Sucessor for the given value in bst
we will compare key with root val and take decision to go 
left or right inorder sucessor is just greater val then key whenever we find
just greater val then key we store and go to left to get more closer value*/