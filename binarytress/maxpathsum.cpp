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
     int maxsum(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int left=max(0,maxsum(root->left,maxi));
        int right=max(0,maxsum(root->right,maxi));
        maxi=max(maxi,left+right+root->val);
        return root->val+max(left,right);

     }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxsum(root,maxi);
        return maxi;
    }
};
/*In this problem we need to find the maximum path sum
Approach:This is a post-order traversal (left → right → root) that:

Computes the maximum path sum passing through each node.

Keeps track of the maximum result seen so far in a global variable (maxi).

the function returns the maximun path sum that can be obtained from the current node to any leaf node 
*/