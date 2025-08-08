#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBst(const vector<int>& arr) {
    Node* root = nullptr;
    for (int val : arr) {
        root = insert(root, val);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBst(arr);
    inorder(root);
    return 0;
}
