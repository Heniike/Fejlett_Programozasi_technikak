
#include "NodeBST.h"
#include <algorithm>
#include <iostream>

using namespace std;

NodeBST::NodeBST() : root(nullptr) {}

NodeBST::~NodeBST() {
    deleteSubTree(root);
}

void NodeBST::insert(int val) {
    root = insertRecursive(root, val);
}

bool NodeBST::find(int val) const {
    return findRecursive(root, val);
}

void NodeBST::print_inorder() const {
    inorder(root);
}

void NodeBST::print_preorder() const {
    preorder(root);
}

void NodeBST::print_postorder() const {
    postorder(root);
}

void NodeBST::inorder(Node* node) const {
    if (node) {
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }
}

void NodeBST::preorder(Node* node) const {
    if (node) {
        std::cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void NodeBST::postorder(Node* node) const {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->val << " ";
    }
}

void NodeBST::deleteSubTree(Node* node) {
    if (node) {
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        delete node;
    }
}

NodeBST::Node* NodeBST::insertRecursive(Node* node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }

    if (val < node->val) {
        node->left = insertRecursive(node->left, val);
    } else if (val > node->val) {
        node->right = insertRecursive(node->right, val);
    }

    return node;
}

bool NodeBST::findRecursive(Node* node, int val) const {
    if (node == nullptr) {
        return false;
    }

    if (val == node->val) {
        return true;
    } else if (val < node->val) {
        return findRecursive(node->left, val);
    } else {
        return findRecursive(node->right, val);
    }
}