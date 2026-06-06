#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    Node* search(Node* node, int val) {
        if (!node || node->data == val)
            return node;
        if (val < node->data)
            return search(node->left, val);
        return search(node->right, val);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    bool search(int val) {
        return search(root, val) != nullptr;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.display();
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not found") << endl;
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not found") << endl;
    return 0;
}
