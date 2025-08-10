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
     int order=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        if(root->left){
            int left=kthSmallest(root->left,k);
            if(left!=-1){
                return left;
            }
        }
        if(order+1==k){
            return root->val;
        }
        order++;
        if(root->right){
            int right=kthSmallest(root->right,k);
            if(right!=-1){
                return right;
            }
        }
        return -1;
        
    }
};
/*In this problem we need to  find the kth smallest number
we know that in BST if we traverse the inorder traversal we get elements in sorted order
we main a order  var that tracks the order  when ever order becomes  equal to k then we return root->val
 */