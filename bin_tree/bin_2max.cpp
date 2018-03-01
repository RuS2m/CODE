#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
int counter = 0;
struct Node {
    std::pair<int, int> value;
    Node* left_child;
    Node* right_child;
};


void add(Node* &node, int value) {
    if (node == nullptr) {
        node = new Node;
        node->value.first = value;
        node->value.second = 1;
        node->left_child = nullptr;
        node->right_child = nullptr;
    } else if (value < node->value.first) {
        add(node->left_child, value);
    } else if (value > node->value.first) {
        add(node->right_child, value);
    } else if (value == node->value.first) {
        node->value.second++;
    }
}

void show(Node* node) {
    if (node != nullptr) {
        show(node->left_child);
        std::cout << node->value.first << " " << node->value.second << "\n";
        show(node->right_child);
    }
}

void showel(Node* node) {
    if (node != nullptr) {
        showel(node->right_child);
        if (counter == 1) {
            std::cout << node->value.first << "\n";
        }
        counter++;
        showel(node->left_child);
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

void leaves(Node* node) {
    if ((node->right_child == nullptr) && (node->left_child == nullptr)) {
        std::cout << node->value.first << '\n';
    } else {
        if (node->left_child != nullptr) {
            leaves(node->left_child);
        }
        if (node->right_child != nullptr) {
            leaves(node->right_child);
        }
    }
}

void crossroad(Node* node) {
    if (node != nullptr) {
        crossroad(node->left_child);
        if ((node->left_child != nullptr) && (node->right_child != nullptr)) {
            std::cout << node->value.first << "\n";
        }
        crossroad(node->right_child);
    }
}

void branch(Node* node) {
    if (node != nullptr) {
        branch(node->left_child);
        if ((node->left_child == nullptr) && (node->right_child != nullptr)) {
            std::cout << node->value.first << "\n";
        }
        if ((node->left_child != nullptr) && (node->right_child == nullptr)) {
            std::cout << node->value.first << "\n";
        }
        branch(node->right_child);
    }
}

int max(Node* node) {
    if (node->right_child != nullptr) {
        max(node->right_child);
    } else {
        return node->value.first;
    }
}

int max2(Node* node) {
    if (node->right_child != nullptr) {
        if (node->right_child->right_child != nullptr) {
            return max2(node->right_child);
        } else if (node->right_child->left_child != nullptr) {
            return max(node->right_child->left_child);
        } else {
            return node->value.first;
        }
    } else {
        return max(node->left_child);
    }
}

bool balansed(Node* node) {
    if (node != nullptr) {
        bool c;
        bool a = balansed(node->left_child);
        if (((depth(node->left_child) - depth(node->right_child)) <= 1)
            && ((depth(node->left_child) - depth(node->right_child)) >= -1)) {
            c = true;
        } else {
            c = false;
        }
        bool b = balansed(node->right_child);
        return a && b && c;
    } else {
        return true;
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
    showel(root);
}

