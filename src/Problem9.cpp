public:
RedBlackTree() : root(nullptr) {}

void Insert(int data) {
    Node *node = new Node(data);
    Node *y = nullptr;
    Node *x = root;

    while (x != nullptr) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;

    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    insertFixup(node);
}

void CountNodesInSubtree() {
    std::vector<int> result;
    countNodesInSubtree(root, result);
    std::cout << "Number of nodes in each subtree: ";
    for (int count : result) {
        std::cout << count << " ";
    }
    std::cout << std::endl;
}

private:
void countNodesInSubtree(Node *node, std::vector<int> &result) {
    if (node != nullptr) {
        int count = 1;
        count += countNodes(node->left);
        count += countNodes(node->right);
        result.push_back(count);
        countNodesInSubtree(node->left, result);
        countNodesInSubtree(node->right, result);
    }
}

int countNodes(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}
};

int main() {
    RedBlackTree rbTree;

    int N;
    std::cout << "Enter the number of nodes (N): ";
    std::cin >> N;

    std::cout << "Enter the values of nodes:" << std::endl;
    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        rbTree.Insert(value);
    }

    rbTree.CountNodesInSubtree();

    return 0;
}