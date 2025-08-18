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
    vector<int>ans;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
        

    }
    TreeNode* buildTree(vector<int>&ans,int i,int j){
        if(i>j) return NULL;
        int mid=i+(j-i)/2;
        TreeNode* build=new TreeNode(ans[mid]);
        build->left=buildTree(ans,i,mid-1);
        build->right=buildTree(ans,mid+1,j);
        return build;
    }
   TreeNode* balanceBST(TreeNode* root) {
        helper(root);
        int i=0;
        int j=ans.size()-1;
        return buildTree(ans,i,j);
        
    } 
};

/*In this problem we have given an unbalance tree
the simple and brute force approach to solve this problem
we traverse the given BST inorder and store all the elements in the array
once we get sorted array have redefine the problem into covert sorted array to BST
*/