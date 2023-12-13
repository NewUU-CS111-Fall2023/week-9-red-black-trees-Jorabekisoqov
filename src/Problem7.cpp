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

    void leftRotate(Node *x) {

    }

    void rightRotate(Node *y) {

    }

    void insertFixup(Node *z) {
       )
    }

    void deleteFix(Node *x) {

    }

    Node *treeMinimum(Node *node) {

    }

    void transplant(Node *u, Node *v) {

    }

    void deleteNode(Node *z) {

    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value) {

    }

    void search(int value) {
        Node *result = searchRec(root, value);
        if (result != nullptr) {
            int height = calculateHeight(result);
            std::cout << value << " is found, its height is " << height << "\n";
        } else {
            std::cout << value << " is not found\n";
        }
    }

    Node *searchRec(Node *node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }

    int calculateHeight(Node *node) {
        int height = 0;
        while (node != nullptr) {
            height++;
            if (node->data < node->parent->data) {
                node = node->parent->left;
            } else {
                node = node->parent->right;
            }
        }
        return height;
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

    int searchValue;
    std::cin >> searchValue;

    tree.search(searchValue);

    return 0;
}