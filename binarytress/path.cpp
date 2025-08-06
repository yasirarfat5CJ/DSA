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
    void allpath(TreeNode* root, vector<string>&ans,string path){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }
        if(root->left){
            allpath(root->left, ans, path + "->" + to_string(root->left->val));
        }
         if(root->right){
           allpath(root->right, ans, path + "->" + to_string(root->right->val));
        }
    
        }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path=to_string(root->val);
        allpath(root,ans,path);
        return ans;
        
    }
};
/*In this problem we have to  print the all the path from root node to leaf node
the path should be in the form of string and nodes should be seprated by '->
we can use recursion to solve this problem when ever we find a node 
with no right and left child we push the path into the ans string vector 
and return from that node
if we find node left or right we call the finction again with left and righr node
*/