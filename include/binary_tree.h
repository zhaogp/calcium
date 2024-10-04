struct BinaryTree {
    int val;
    BinaryTree *left;
    BinaryTree *right;

    // 构造器
    BinaryTree(int x): val(x), left(nullptr), right(nullptr) {

    }
};

void recurisiveTree(BinaryTree* root);
