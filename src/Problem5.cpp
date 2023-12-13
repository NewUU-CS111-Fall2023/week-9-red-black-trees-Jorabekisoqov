#include <iostream>

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    Node* insertRec(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    void countChildren() {
        countChildrenRec(root);
    }

    void countChildrenRec(Node* node) {
        if (node != nullptr) {
            int numChildren = 0;

            if (node->left != nullptr) {
                numChildren++;
            }

            if (node->right != nullptr) {
                numChildren++;
            }

            std::cout << "Node " << node->data << ": " << numChildren << " children\n";

            countChildrenRec(node->left);
            countChildrenRec(node->right);
        }
    }
};

int main() {
    int N;
    std::cin >> N;

    BinaryTree tree;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        tree.insert(value);
    }

    std::cout << "Number of children for each node:\n";
    tree.countChildren();

    return 0;
}
