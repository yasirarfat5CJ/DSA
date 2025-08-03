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
    int diameter(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int lh=diameter(root->left,maxi);
        int rh=diameter(root->right,maxi);
        maxi=max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        diameter(root,maxi);
        return maxi;
        
    }
};
/* In this problem we need to find the diameter of binary tree that is
The diameter is the length of the longest path between any two nodes in the tree.

The path does not necessarily pass through the root.

The length is measured in number of edges (not number of nodes).

Approch:we will use a recursive function to calculate the  height of the left and right subtree
This is a post-order traversal function that:

Calculates the height of the current node.

Updates the global maxi with the maximum left height + right height.

thre maxi will give us the diameter of the tree


*/