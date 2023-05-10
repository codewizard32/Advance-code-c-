#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void BFS(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr->data << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
        q.pop();
    }
}

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Node* root = newNode(15);
    root->left = newNode(4);
    root->right = newNode(18);
    root->left->left = newNode(20);
    root->left->right = newNode(50);
    root->right->left = newNode(6);
    root->right->right = newNode(3);

    cout << "BFS traversal: ";
    BFS(root);

    return 0;
}