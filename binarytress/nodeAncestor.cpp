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
    int helper(TreeNode* root,int maxval,int minval){
        if(!root) return maxval-minval;
        maxval=max(root->val,maxval);
        minval=min(root->val,minval);
        int left=helper(root->left,maxval,minval);
        int right=helper(root->right,maxval,minval);
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return helper(root,root->val,root->val);

        
    }
};

/*In this problem we need to find the  max diff of every path and return max value
if we want to maximize some thing we need max and min values so  we keep track max val and min val 
at every path when we reach to null node then we calculate maxval-minval and keep track of maxdiff

*/