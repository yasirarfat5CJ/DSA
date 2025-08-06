#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int idx = -1;

Node* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}
int transformSumTree(Node* root){
    if(root==NULL) return 0;
    int leftsum=transformSumTree(root->left);
     int rightsum=transformSumTree(root->right);
     root->data+=leftsum+rightsum;
     return root->data;
    
}
void  preOrder(Node* root){
    if(root==NULL){
        return;
    }
   
    cout<< root->data <<" ";
     preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
  
    preOrder(root);
    transformSumTree(root);
    cout<< " "<<endl;
    preOrder(root);
}
/*in this problem we have to transform  ourbinary tree to sum tree
we will traverse in post order fashion and calculate left and right subtree sum
then will assing root->data to left+right and root data
*/