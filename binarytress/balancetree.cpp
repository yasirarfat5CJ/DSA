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
    int check(TreeNode* root){
        if(root==NULL) return 0;
        int lh=check(root->left);
        int rh=check(root->right);
        if(lh==-1||rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
        
    }
};
/*In this problem we ned to check wheather thr tree is balances or not 
Appproch:A binary tree is height-balanced if for every node, 
the difference between the height of the left subtree and the right subtree is at most 1.
we wiil check the height of left subtreea and right subtree
if the difference is greater than 1 then we will return -1
if the difference is less than or equal to 1then we will return the height of the tree
if we get  -1  at any  point then we will return false 
*/