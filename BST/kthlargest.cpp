class Solution {
public:
    int order = 0;
    int kthLargest(TreeNode* root, int k) {
        if (root == NULL) return -1;

        // First go right (largest values first)
        if (root->right) {
            int right = kthLargest(root->right, k);
            if (right != -1) {
                return right;
            }
        }

        // Visit root
        if (order + 1 == k) {
            return root->val;
        }
        order++;

        // Then go left
        if (root->left) {
            int left = kthLargest(root->left, k);
            if (left != -1) {
                return left;
            }
        }

        return -1;
    }
};
/*reverse the traversal */