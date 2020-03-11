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

    bst_preorder(root);
    //bst_preorder(root, func);
    /*if(bst_successor(root, root) != nullptr){
        cout << "O sucessor do : " << root->key << " = " << bst_successor(root, root)->key << endl;
    }else{
        cout << "O nó passado é o maior nó da arvore" << endl;
    }*/
    if(bst_predecessor(root,bst_search(root, 5)) == nullptr){
        cout << "Não foi possivel encontrar o predecessor do valor passado" << endl;    
    }else{
        cout << bst_search(root, 5)->key << " predecessor -> " << bst_predecessor(root,bst_search(root, 5))->key << endl;
    }
    
    //cout << bst_height(root) << endl;
    root = bst_clear(root);

    return 0;
}