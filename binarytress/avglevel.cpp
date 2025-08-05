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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(root==NULL){
            return ans;

        }
        queue<TreeNode*>q;
        q.push(root);
      
        while(!q.empty()){
            int n=q.size();
            long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
               
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            double avg=(double)sum/n;
            ans.push_back(avg);
        }
        return ans;
        
    }
};
/*In this problem we need to find the avg of each  level of the tree
Approach: weuse the technique of level order traversal
we sum up the calues once level is completed we
calculate avg and push it into ans vector
*/