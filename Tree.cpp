#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    // Insert a new node in the binary tree
    Node* insertNode(Node* node, int data) {
        if (!node) return new Node(data);

        if (data < node->data) {
            node->left = insertNode(node->left, data);
        } else {
            node->right = insertNode(node->right, data);
        }
        return node;
    }

    void insert(int data) {
        root = insertNode(root, data);
    }

    // Inorder traversal (Left, Root, Right)
    void inorderTraversal(Node* node) {
        if (!node) return;

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Preorder traversal (Root, Left, Right)
    void preorderTraversal(Node* node) {
        if (!node) return;

        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // Postorder traversal (Left, Right, Root)
    void postorderTraversal(Node* node) {
        if (!node) return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    // Search for a value in the binary tree
    bool search(Node* node, int data) {
        if (!node) return false;

        if (node->data == data) return true;
        else if (data < node->data) return search(node->left, data);
        else return search(node->right, data);
    }

    bool search(int data) {
        return search(root, data);
    }

    // Find the minimum value node in the tree
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // Delete a node from the binary tree
    Node* deleteNode(Node* node, int data) {
        if (!node) return node;

        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            // Node with only one child or no child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void deleteValue(int data) {
        root = deleteNode(root, data);
    }

    // Utility functions for traversal
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    // Insert values
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Display the tree in different orders
    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    // Search for a value
    int searchValue = 4;
    if (tree.search(searchValue)) {
        cout << "Value " << searchValue << " found in the tree." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the tree." << endl;
    }

    // Delete a node
    int deleteValue = 3;
    cout << "Deleting value " << deleteValue << " from the tree." << endl;
    tree.deleteValue(deleteValue);

    cout << "Inorder Traversal after deletion: ";
    tree.inorder();

    return 0;
}
