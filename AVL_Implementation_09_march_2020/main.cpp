#include <bits/stdc++.h>
#include "avl.h"
#include "item.h"

using namespace std;

int main(){
    Node* root = nullptr;

    root = avl_insert(root, "a", "ab");
    root = avl_insert(root, "b", "bc");
    root = avl_insert(root, "c", "cd");

    avl_preorder(root);

}