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
    TreeNode*  helper(vector<int>& nums,int st,int end){
        if(st>end) return NULL;
        int mid=st+(end-st)/2;
         TreeNode* root=new  TreeNode(nums[mid]);
         root->left=helper(nums,st,mid-1);
         root->right=helper(nums,mid+1,end);
         return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
        
    }
};

/*In this problem we are given nums arr we want to build bst
Approach: we calculate the mid of the nums and create a root
and 0 to mid-1 we call recursively function for left subtree 
and same for right subtree from mid+1 to end 
*/