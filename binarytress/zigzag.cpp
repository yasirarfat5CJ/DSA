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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue<TreeNode*>q;

        q.push(root);
        bool islefttoright=true;

        while(!q.empty()){
            int levelsize=q.size();
            vector<int>level(levelsize);
            for(int i=0;i<levelsize;++i){
                TreeNode* node=q.front();
                q.pop();

                int index= islefttoright?i:(levelsize-1-i);
                level[index]=node->val;

                if(node->left) q.push(node->left);
                 if(node->right) q.push(node->right);

            }
            res.push_back(level);
            islefttoright=!islefttoright;


        }
        return res;
        
    }
};
/*In this problem we need to tarvese in zig zag manner 
so we use the technique of level order traversal .we maintain a variable 
called islefttoright which keeps track of where we r moving
either left to right or right to left if  it is true then left to right and vice versa
if we found true we place the node at ith index and we find false we place the node at size-1-i because
we r moving right to left at every level we toggle islefttoright */