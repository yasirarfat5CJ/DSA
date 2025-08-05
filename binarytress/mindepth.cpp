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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int depth=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left==NULL && curr->right==NULL){
                    return depth;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            depth++;
        }
        return depth;
      
        
    }
};
/*In this problem we need to find the minimum depth of the tree
as we know that when we go from top to bottom the size of the tree increase
so we will use the technique of levelorder traversal
whenever we find the node with no children we return depth
*/