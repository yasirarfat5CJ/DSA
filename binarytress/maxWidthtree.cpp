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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        unsigned long long maxi=0;
        while(!q.empty()){
            int n=q.size();
            unsigned long long stidx=q.front().second;
            unsigned long long enidx=q.back().second;
            maxi=max(maxi,enidx-stidx+1);
            for(int i=0;i<n;i++){
                auto curr=q.front();
                q.pop();
                if(curr.first->left){
                    q.push({curr.first->left,curr.second*2+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right,curr.second*2+2});
                }
            }
           

        }
        return maxi;
        
    }
};

/*In this problem we need to calculate the maximum width of tree
we can use level order traversal technique to solve
we use concept of indexingto calculate the width of each level as we also have
to consider null nodes in  the tree
if the rott is stored at indes i then left child will 
be at  2*i+1 and right  child  will be at 2*i+2
this is the main logic behind this problem 
at last we will return maxi which will be the maximum width of the tree
*/