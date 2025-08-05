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
     TreeNode* buildTree(vector<int>& nums,int st,int end){
        if(st>end) return NULL;
        int idxmax=st;
        for(int i=st+1;i<=end;i++){
            if(nums[i]>nums[idxmax]){
                idxmax=i;
            }
        }
        TreeNode* root=new TreeNode(nums[idxmax]);
        root->left=buildTree(nums,st,idxmax-1);
        root->right=buildTree(nums,idxmax+1,end);
        return root;
     }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return  buildTree(nums,0,nums.size()-1);
    }
};

/*In thisproblem we need to contruct b tree from the given array
Approach: we will find max element in the array and make the root and after that we will 
construct left and right subtree recursively by using the idx of largest element
*/