#include <bits/stdc++.h>
#include "RBTree.h"
#include "Item.h"

using namespace std;

int main(){
    RBTree tree = RBTree();

    tree.insert(5, "a");
    tree.insert(4, "b");
    tree.insert(6, "c");
    tree.insert(7, "d");
    tree.insert(8, "e");
    tree.insert(9, "f");
    tree.insert(10, "g");
    tree.insert(20, "h");
    tree.preorder();
    tree.~RBTree();
}