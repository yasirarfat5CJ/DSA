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

// Function to build the binary tree from preorder traversal with -1 as NULL
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

// Print nodes at Kth level
void printKthLevel(Node* root, int k) {
    if (root == NULL) return;

    if (k == 1) {
        cout << root->data << " ";  
        return;
    }

    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}


void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    int k = 3; 

    cout << "Preorder traversal: ";
    preOrder(root);

    cout << "\nNodes at level " << k << ": ";
    printKthLevel(root, k);

    return 0;
}


/*In this problem we have to print kth level of binary tree
we follow the  approach of preorder traversal 
and every time we decrease k when k==1
we print roots data */