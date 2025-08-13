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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                level.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.insert(res.begin(),level);
            
        }
       
        return res;

        
    }
}
/*this problem is same like level order but we need to travese bottom up traversal
here we use brute force approach to solve  this problem
simply we are doing level order traversal at every after level we are inserting the 
level at the begining using res.begin() function*/