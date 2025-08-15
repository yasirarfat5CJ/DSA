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
    vector<int> helper(TreeNode* root,vector<int>ans){
        if(!root) return ans;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val);
            return ans;
        }
        if(root->left){
           ans= helper(root->left,ans);
        }
        if(root->right){
           ans= helper(root->right,ans);
        }
        return ans;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        vector<int>ans1=helper(root1,ans);
        vector<int>ans2=helper(root2,ans);
        int n1=ans1.size();
        int n2=ans2.size();
        if(n1!=n2) return false;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(ans1[i]!=ans2[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;

    }
}
/*In this problem we r given two tress we need to check
all the leaf node values are same or not of two tress
for that we traverse both the tress and store all the leaf value 
in vectors and compare if they  r equal  we  return true
otherwise we return false */