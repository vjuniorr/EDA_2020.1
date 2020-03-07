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
    Node* Sl2 = nullptr;
    Node* Sr2 = nullptr;

    /*root = bst_insert(root, 20, 45.9);
    root->left = bst_insert(root, 10, 5.5);
    root->right = bst_insert(root, 25, 6.6);
    Sr = root->right->right = bst_insert(root, 30, 7.7);
    Sr->left = bst_insert(root, 26, 6.7);*/

    root = bst_insert(root, 8, 5.5);
    root->left = Sl = bst_insert(root, 3, 3.5);
    root->right = Sr = bst_insert(root, 13, 13.6);
    Sl->right = Sl2 = bst_insert(root, 7 , 6.5);
    Sl->left = bst_insert(root, 1 , 8.5);
    Sr->left = Sr2 = bst_insert(root, 10, 8.3);
    Sl2->left = bst_insert(root, 4, 9.9);
    Sr2->right = bst_insert(root, 12, 5.5);

    bst_preorder(root);
    //bst_preorder(root, func);
    if(bst_successor(root, root) != nullptr){
        cout << "O sucessor do : " << root->key << " = " << bst_successor(root, root)->key << endl;
    }else{
        cout << "O nó passado é o maior nó da arvore" << endl;
    }
    //cout << bst_height(root) << endl;
    root = bst_clear(root);

    return 0;
}