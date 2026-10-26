// Implement a BST class (integer keys, duplicates not allowed) with the following operations:
//     1. insert(key)
//     2. search(key)
//     3. delete(key) : must correctly handle all three cases: leaf, one child, two children
//       (using inorder successor).
//     4. findMin() , findMax() , and height()
//     5. inorderSuccessor(key) without using parent pointers
// Analysis: Insert the keys 10, 20, 30, 40, 50, 25 into an empty BST and draw the result. State the
// best-case and worst-case time of each operation and explain what causes the worst case.

#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int value)
    {
        key = value;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node *root;

    Node* insert(Node *node, int key)
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        return node; 
    }

    bool search(Node *node, int key)
    {
        if (node == nullptr)
            return false;

        if (node->key == key)
            return true;

        if (key < node->key)
            return search(node->left, key);

        return search(node->right, key);
    }

    Node* findMinNode(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    Node* findMaxNode(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        while (node->right != nullptr)
            node = node->right;

        return node;
    }

    Node* deleteNode(Node *node, int key)
    {
        if (node == nullptr)
            return nullptr;

        if (key < node->key)
            node->left = deleteNode(node->left, key);

        else if (key > node->key)
            node->right = deleteNode(node->right, key);

        else
        {
            // Case 1: No children
            if (node->left == nullptr &&
                node->right == nullptr)
            {
                delete node;
                return nullptr;
            }

            // Case 2: Only right child
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: Only left child
            if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            Node *temp = findMinNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }

        return node;
    }

    int getHeight(Node *node)
    {
        if (node == nullptr)
            return -1;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;

        return rightHeight + 1;
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void destroy(Node *node)
    {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        destroy(root);
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    bool search(int key)
    {
        return search(root, key);
    }

    void deleteKey(int key)
    {
        root = deleteNode(root, key);
    }

    int findMin()
    {
        Node *temp = findMinNode(root);

        if (temp == nullptr)
        {
            cout << "Tree is empty\n";
            return -1;
        }

        return temp->key;
    }

    int findMax()
    {
        Node *temp = findMaxNode(root);

        if (temp == nullptr)
        {
            cout << "Tree is empty\n";
            return -1;
        }

        return temp->key;
    }

    int height()
    {
        return getHeight(root);
    }

    int inorderSuccessor(int key)
    {
        Node *current = root;
        Node *successor = nullptr;

        while (current != nullptr && current->key != key)
        {
            if (key < current->key)
            {
                successor = current;
                current = current->left;
            }
            else
                current = current->right;
        }

        if (current == nullptr)
            return -1; // Key not found

        if (current->right != nullptr)
            return findMinNode(current->right)->key;

        if (successor != nullptr)
            return successor->key;

        return -1; // No successor
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder: ";
    tree.display();

    cout << "Search 25: " << tree.search(25) << endl;
    cout << "Minimum: " << tree.findMin() << endl;
    cout << "Maximum: " << tree.findMax() << endl;
    cout << "Height: " << tree.height() << endl;

    int successor = tree.inorderSuccessor(25);

    if (successor != -1)
        cout << "Successor of 25: " << successor << endl;
    else
        cout << "No successor found\n";

    tree.deleteKey(30);

    cout << "After deleting 30: ";
    tree.display();

    return 0;
}
