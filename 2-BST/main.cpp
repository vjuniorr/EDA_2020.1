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

    root = bst_insert(root, 8, 1.0);
    root = bst_insert(root, 3, 2.0);
    root = bst_insert(root, 13, 3.0);
    root = bst_insert(root, 7 , 4.0);
    root = bst_insert(root, 14, 5.0);
    root = bst_insert(root, 1, 6.0);
    root = bst_insert(root, 10, 7.0);
    root = bst_insert(root, 12, 8.0);
    root = bst_insert(root, 4, 9.0);
    root = bst_insert(root, 5, 10.0);

    avl_level_traversal(root);
    cout << endl;
    //bst_preorder(root, func);
    /* if(bst_successor(root, bst_search(root, 14)) != nullptr){
        cout << "O sucessor do : " << bst_search(root, 14)->key << " = " << bst_successor(root, bst_search(root, 14))->key << endl;
    }else{
        cout << "Nao foi possivel encontrar o sucessor" << endl;
    } */
    /*if(bst_predecessor(root,bst_search(root, 5)) == nullptr){
        cout << "Não foi possivel encontrar o predecessor do valor passado" << endl;    
    }else{
        cout << bst_search(root, 5)->key << " predecessor -> " << bst_predecessor(root,bst_search(root, 5))->key << endl;
    }*/
    
    //bst_remove(root, 3);
    //bst_preorder(root);

    //cout << bst_height(root) << endl;
    root = bst_clear(root);

    return 0;
}