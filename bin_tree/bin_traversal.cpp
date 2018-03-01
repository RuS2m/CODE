#include <cmath>
#include <iostream>

struct Node {
    int value;
    Node* left_child;
    Node* right_child;
};


void add(Node* &node, int value) {
    if (node == nullptr) {
        node = new Node;
        node->value = value;
        node->left_child = nullptr;
        node->right_child = nullptr;
    } else if (value < node->value) {
        add(node->left_child, value);
    } else if (value > node->value) {
        add(node->right_child, value);
    }
}

void delete_node(Node* node) {
    if (node != nullptr) {
        delete_node(node->left_child);
        delete_node(node->right_child);
        delete node;
    }
}

void show(Node* node) {
    if (node != nullptr) {
        show(node->left_child);
        std::cout << node->value << "\n";
        show(node->right_child);
    }
}

int depth(Node* node) {
    if (node != nullptr) {
        if (depth(node->left_child) > depth(node->right_child)) {
            return (1 + depth(node->left_child));
        } else {
            return (1 + depth(node->right_child));
        }
    } else {
        return 0;
    }
}

int main() {
    Node* root = nullptr;
    int number = 1;
    std::cin >> number;
    while (number != 0) {
        add(root, number);
        std::cin >> number;
    }
    show(root);
    delete(root);
}
