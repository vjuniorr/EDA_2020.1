#include <bits/stdc++.h>
#include "avl.h"
#include "item.h"

using namespace std;

int main(){
    Node* root = nullptr;

    root = avl_insert(root, "b", "b");
    root = avl_insert(root, "a", "a");
    root = avl_insert(root, "c", "c");
    root = avl_insert(root, "d", "d");
    root = avl_insert(root, "e", "e");
    root = avl_insert(root, "f", "f");

    avl_preorder(root);
    cout << avl_balance(root) << endl;
}