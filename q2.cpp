#include <iostream>
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

class BST
{
public:
    Node *root;
    BST() { root = nullptr; }

    // Insert (non-recursive)
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!root)
        {
            root = newNode;
            return;
        }
        Node *parent = nullptr;
        Node *current = root;
        while (current)
        {
            parent = current;
            if (val < current->data)
                current = current->left;
            else
                current = current->right;
        }
        if (val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    // (a) Search (non-recursive)
    Node *search(int key)
    {
        Node *current = root;
        while (current)
        {
            if (current->data == key)
                return current;
            else if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }

    // (b) Maximum element
    int findMax()
    {
        if (!root)
            return -1;
        Node *current = root;
        while (current->right)
            current = current->right;
        return current->data;
    }

    // (c) Minimum element
    int findMin()
    {
        if (!root)
            return -1;
        Node *current = root;
        while (current->left)
            current = current->left;
        return current->data;
    }

    // (d) In-order successor of a given node
    Node *inOrderSuccessor(int key)
    {
        Node *current = root;
        Node *successor = nullptr;
        while (current)
        {
            if (key < current->data)
            {
                successor = current;
                current = current->left;
            }
            else if (key > current->data)
            {
                current = current->right;
            }
            else
            {
                if (current->right)
                {
                    current = current->right;
                    while (current->left)
                        current = current->left;
                    successor = current;
                }
                break;
            }
        }
        return successor;
    }

    // (e) In-order predecessor of a given node
    Node *inOrderPredecessor(int key)
    {
        Node *current = root;
        Node *predecessor = nullptr;
        while (current)
        {
            if (key > current->data)
            {
                predecessor = current;
                current = current->right;
            }
            else if (key < current->data)
            {
                current = current->left;
            }
            else
            {
                if (current->left)
                {
                    current = current->left;
                    while (current->right)
                        current = current->right;
                    predecessor = current;
                }
                break;
            }
        }
        return predecessor;
    }

    // Display (inorder)
    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void display()
    {
        cout << "BST (In-order): ";
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;
    // Build BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.display();

    // (a) Search
    int key = 60;
    Node *result = tree.search(key);
    cout << "\nSearch " << key << ": " << (result ? "Found" : "Not Found") << endl;

    // (b) Maximum
    cout << "Maximum Element: " << tree.findMax() << endl;

    // (c) Minimum
    cout << "Minimum Element: " << tree.findMin() << endl;

    // (d) In-order Successor
    int key1 = 50;
    Node *succ = tree.inOrderSuccessor(key1);
    if (succ)
        cout << "In-order Successor of " << key1 << ": " << succ->data << endl;
    else
        cout << "In-order Successor of " << key1 << " does not exist\n";

    // (e) In-order Predecessor
    int key2 = 50;
    Node *pred = tree.inOrderPredecessor(key2);
    if (pred)
        cout << "In-order Predecessor of " << key2 << ": " << pred->data << endl;
    else
        cout << "In-order Predecessor of " << key2 << " does not exist\n";

    return 0;
}
