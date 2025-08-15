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
    int sum=0;
    int leafsum(TreeNode* root,bool val){
        if(!root) return 0;
        if(!root->left && !root->right){
            if(val==true){
                sum+=root->val;
            }
            return sum;
        }
        if(root->left){
            leafsum(root->left,true);
        }
        if(root->right){
            leafsum(root->right,false);
        }
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return leafsum(root,false);
        
        
    }
};

/*In this problemm we need to cal
the the sum of nodes values which exist at left with no left and 
right child the approach is simple dfs by maintaing a boolean var 
whenever we move left we pass as true when we reach to node with no child we check var 
if it is true then we add to sum */