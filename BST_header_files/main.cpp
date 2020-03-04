#include <bits/stdc++.h>
#include "item.h"
#include "bst.h"

using namespace std;

struct Node {
    Tkey key;
    Tvalue value;
    Node* left;
    Node* right;
};

void func(Node* node){
    cout << (2 * bst_getKey(node)) << endl;
}

int main(){
    Node* root = nullptr;
    Node* Sl = nullptr;
    Node* Sr = nullptr;

    root = bst_insert(root, 20, 45.9);
    root->left = bst_insert(root, 10, 5.5);
    root->right = bst_insert(root, 25, 6.6);
    root->right->right = bst_insert(root, 30, 7.7);

    bst_preorder(root);
    bst_preorder(root, func);
    cout << bst_height(root) << endl;
    root = bst_clear(root);

    return 0;
}