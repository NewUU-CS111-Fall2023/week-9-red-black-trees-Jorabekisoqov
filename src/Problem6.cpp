#include <iostream>

enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node *root;

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
        root->color = BLACK; // Ensure the root is always black
    }

    Node *insertRec(Node *root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
            root->left->parent = root;
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
            root->right->parent = root;
        }

        return root;
    }

    void calculateAndDisplayBlackHeight() {
        calculateAndDisplayBlackHeightRec(root);
    }

    void calculateAndDisplayBlackHeightRec(Node *node) {
        if (node != nullptr) {
            int blackHeight = calculateBlackHeight(node);
            std::cout << "Node " << node->data << ": Black Height = " << blackHeight << "\n";

            calculateAndDisplayBlackHeightRec(node->left);
            calculateAndDisplayBlackHeightRec(node->right);
        }
    }

    int calculateBlackHeight(Node *node) {
        int blackHeight = 0;
        while (node != nullptr) {
            if (node->color == BLACK) {
                blackHeight++;
            }
            node = node->left; // Traverse to the leftmost child
        }
        return blackHeight;
    }
};

int main() {
    int N;
    std::cin >> N;

    RedBlackTree tree;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        tree.insert(value);
    }

    std::cout << "Black Height for each node:\n";
    tree.calculateAndDisplayBlackHeight();

    return 0;
}