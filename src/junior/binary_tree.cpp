#include <iostream>
#include "binary_tree.h"

using namespace std;


// 二叉树前序遍历
void preOrderRecurisive(BinaryTree* root) {
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preOrderRecurisive(root->left);
    preOrderRecurisive(root->right);
}

// 二叉树中序遍历
void inOrderRecurisive(BinaryTree* root) {
    if (root == nullptr)
        return;
    
    inOrderRecurisive(root->left);
    cout << root->val << " ";
    inOrderRecurisive(root->right);
}

// 二叉树后序遍历
void postOrderRecurisive(BinaryTree* root) {
    if (root == nullptr)
        return;

    postOrderRecurisive(root->left);
    postOrderRecurisive(root->right);
    cout << root->val << " ";
}

// 二叉树遍历
void recurisiveTree(BinaryTree* root) {

    cout << "前序遍历" << endl;
    preOrderRecurisive(root);
    cout << endl;

    cout << "中序遍历" << endl;
    inOrderRecurisive(root);
    cout << endl;

    cout << "后序遍历" << endl;
    postOrderRecurisive(root);
    cout << endl;
}
