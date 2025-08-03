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
   int count(TreeNode* root){
    if(root==NULL) return 0;
    int leftcount=count(root->left);
    int rightcount=count(root->right);
    return leftcount+rightcount+1;
   }

    int countNodes(TreeNode* root) {
    return count(root);
        
    }
};
/* In this problem we need to calculate the number of nodes in the tree

we will follow the same approach we will the number of nodes in left sutree and number of nodes in right subtree
will add them  and also we add 1  extra for root node \
this will give number of nodes in the tree */