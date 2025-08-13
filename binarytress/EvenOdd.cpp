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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(q.size()>0){
            int n=q.size();
            int prev= (level%2==0)?INT_MIN:INT_MAX;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(level%2==0){
                    if(curr->val<=prev || curr->val%2==0) return false;
                }else{
                    if(curr->val>=prev || curr->val%2!=0) return false;
                }
                prev=curr->val;
                
               
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        return true;
        
    }
};

/*In this problem we need to ccheck the values of nodes at level wise
at odd level the values must be in decreasing order
at even levels the values must be in increasingorder
to solve this problem we use the technique of level order traversal
we keep tack of prev value initally it is assing as max or min bases on level
if level is odd we check for false condition that is if currrent val is greater  then prev
then we return false and vice versa for even  every time we update the prev
*/