
#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree() { root = nullptr; }

    // Utility function to check BST property
    bool isBSTUtil(Node *node, int minVal, int maxVal)
    {
        if (!node)
            return true;
        if (node->data <= minVal || node->data >= maxVal)
            return false;
        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }

    bool isBST()
    {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};

int main()
{
    BinaryTree tree;
    tree.root = new Node(4);
    tree.root->left = new Node(2);
    tree.root->right = new Node(6);
    tree.root->left->left = new Node(1);
    tree.root->left->right = new Node(3);

    cout << (tree.isBST() ? "Tree is a BST" : "Tree is NOT a BST") << endl;

    // Add a violation
    tree.root->right->left = new Node(10); // breaks BST rule
    cout << (tree.isBST() ? "Tree is a BST" : "Tree is NOT a BST") << endl;

    return 0;
}
