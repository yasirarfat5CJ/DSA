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
    int helper(TreeNode* root,TreeNode* parent,TreeNode* Grandparent){
        if(root==NULL) return 0;
        if(Grandparent  && Grandparent->val%2==0){
            sum+=root->val;
        }
        helper(root->left,root,parent);
         helper(root->right,root,parent);
         return sum;
    }
    int sumEvenGrandparent(TreeNode* root) {
       
        return helper(root,NULL,NULL);
    }
};

/*In this problemm we need to return the sum of nodes whose grand parent is even
so we will take two addional nodes which  is initialized as null
the purpose of this two nodes is to keep track of parent and Grandparent we 
call recursively function left and right subree and update parent to rrot and Gp to parent 
whenever we found Gp is exist and its value  is even then we add that value to sum
at last we return sum*/