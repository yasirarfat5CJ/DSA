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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        TreeNode* build=new TreeNode(root1->val+root2->val);
        build->left=mergeTrees(root1->left,root2->left);
        build->right=mergeTrees(root1->right,root2->right);
        return build;
        
        
        
    }
};
/*In this  problem we need to merge two binaey treees
if we encounter any node that is overlapping we need add the value of that two nodes
and make it as a single node .always root will operlap
so we make a newnode with addition of values .and we recursively call for left and right subtree
if root1 left  suntree  is null and root2 is not null we return root2
and vice versa
*/