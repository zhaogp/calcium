/*
    主入口文件
*/
#include <iostream>

#include "junior/binary_tree.h"
#include "math_functions/my_tools.h"

using namespace std;


int main() {
    // 示例二叉树:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);

    recurisiveTree(root);
    cout << "complete" << endl;

    sqrt(2);

    return 0;
}
