
#include <iostream>
#include <algorithm> // for max() and min()
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
public:
    Node *root;
    BST() { root = nullptr; }

    // (a) Insert (no duplicates allowed)
    Node *insert(Node *node, int val)
    {
        if (!node)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        // duplicates not allowed
        return node;
    }

    // Helper function to find minimum node in a subtree
    Node *findMin(Node *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // (b) Delete an existing element
    Node *deleteNode(Node *node, int val)
    {
        if (!node)
            return nullptr;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else
        {
            // Node found
            if (!node->left && !node->right)
            {
                delete node;
                return nullptr;
            }
            else if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node *temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    // (c) Maximum depth (height)
    int maxDepth(Node *node)
    {
        if (!node)
            return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    // (d) Minimum depth
    int minDepth(Node *node)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return 1;
        if (!node->left)
            return 1 + minDepth(node->right);
        if (!node->right)
            return 1 + minDepth(node->left);
        return 1 + min(minDepth(node->left), minDepth(node->right));
    }

    // In-order traversal for displaying BST
    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main()
{
    BST tree;

    // (a) Insert elements (no duplicates)
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "BST (In-order): ";
    tree.inorder(tree.root);
    cout << endl;

    // (b) Delete a node
    cout << "\nDeleting 20...\n";
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "After deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    // (c) Maximum depth
    cout << "\nMaximum Depth of BST: " << tree.maxDepth(tree.root) << endl;

    // (d) Minimum depth
    cout << "Minimum Depth of BST: " << tree.minDepth(tree.root) << endl;

    return 0;
}
