#include <bits/stdc++.h>
#include "item.h"
#include "bst.h"

using namespace std;

void func(Node* node){
    cout << 2 * bst_getKey(node) << endl;
}

int main(){
    Node* root = nullptr;

    root = bst_insert(root, 20, 45.9);
    bst_preorder(root);
    bst_preorder(root, func);
    root = bst_clear(root);

    return 0;
}