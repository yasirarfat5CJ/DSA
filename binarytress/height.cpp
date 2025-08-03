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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int leftht=height(root->left);
        int rightht=height(root->right);
        return max(leftht,rightht)+1;
    
    }
    int maxDepth(TreeNode* root) {
        return height(root);

        
    }
};

/* in this problem we need to calculate the height of thr tree 
  Approach: we will calculate thr left height of the tree and  we will calculate right height 
  of the the tree 
  we will take max of both and add 1 to it
  this will give tthr height of the tree 
  */