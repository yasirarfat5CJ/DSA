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
    bool isidentical(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL){
            return p==q;
        }
        return p->val==q->val && isidentical(p->left,q->left) && isidentical(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL){
            return root==subRoot;
        }
        if(root->val==subRoot->val && isidentical(root,subRoot)){
            return true;
        }
       return isSubtree(root->left,subRoot) ||
        isSubtree(root->right,subRoot);
        
    }
};
/*In this problem we need to check the given subtree is the part of main tree or not
Approach:we will check the root of the subtree in the main tree if we find the root of the subtree in the main
tree then we will check for identicality of both trees
if they are identical then we will return true
else false
and also  if we dont find the root of the subtree in the main tree we will return false
*/