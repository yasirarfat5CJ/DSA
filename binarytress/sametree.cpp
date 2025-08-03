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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return p==q;
        }
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        return p->val==q->val && left && right;
        
    }
};
/*In this problem we need to check wheather  two binary tree are  same or not
Approach:Two binary trees are considered the same if they are structurallyy idebtical,
and the nodes have the same value.
we will check tg both the left and right tree root is null then we return true.
otherwise  we will call function for both left and right subtree
tf both left and right subtree are same and the value of root nodes are  same then we return true
otherwise we return false 


*/