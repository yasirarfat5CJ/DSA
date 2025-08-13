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
    vector<int> largestValues(TreeNode* root) {
         vector<int>ans;
        if(!root) return ans;
       
       
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            int maxVal=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                
                q.pop();
                 maxVal=max(curr->val,maxVal);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
           ans.push_back(maxVal);
        }
        return ans;

        
    }
};

/* In this problem we need to find the largest value in each row
same like level order traversal we travease every node in each level
by keeping track max val using max function
after every level we  push the maxval into the ans and  re assing max as min

*/