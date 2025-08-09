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
    TreeNode* getIS(TreeNode* root){
        while(root!=NULL && root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key < root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right=deleteNode(root->right,key);
        }else{
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }else if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }else{
                TreeNode* IS=getIS(root->right);
                root->val=IS->val;
                root->right=deleteNode(root->right,IS->val);
            }
        }
        return root;
    }
};

/*
In this pproblem we need to delete a node 
there are three conditions which comes while while deleting the node 
first there is no children in this case we delete a node and return null\
second case id there is one children in this case we to the right or left child which is
not null in temp and we return that temp
third case id if there are two childern then we fid the inorder sucessor 
that is nothing but leftmost node of right subtree
we replace this IS with root and delete the node 
*/