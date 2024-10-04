#include <iostream>
#include "binary_tree.h"

using namespace std;


// 二叉树


// 递归实现
void preOrderRecurisive(BinaryTree* root) {
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preOrderRecurisive(root->left);
    preOrderRecurisive(root->right);
}

void inOrderRecurisive(BinaryTree* root) {
    if (root == nullptr)
        return;
    
    inOrderRecurisive(root->left);
    cout << root->val << " ";
    inOrderRecurisive(root->right);
}

void postOrderRecurisive(BinaryTree* root) {
    if (root == nullptr)
        return;

    postOrderRecurisive(root->left);
    postOrderRecurisive(root->right);
    cout << root->val << " ";
}

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
