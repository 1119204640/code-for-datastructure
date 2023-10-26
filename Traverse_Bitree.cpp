#include <iostream>
using namespace std;

#define N 10 //节点个数

typedef struct TreeNode{
    int val;
    struct TreeNode *left, *right;
}*Bitree;

//二叉树的顺序存储转链式存储
Bitree ToLink(int tree[], int i){
    Bitree root;
    if (i < N) {
        root->val = tree[i];
        root->left = ToLink(tree, 2*i+1);
        root->right = ToLink(tree, 2*i+2);
    }
    return root;
}

//递归先序遍历
void Preorder_recur(Bitree root, int* res, int* returnSize) {
    if (root != NULL) {
        res[*(returnSize)++] = root->val;
        Preorder_recur(root->left, res, returnSize);
        Preorder_recur(root->right, res, returnSize);
        
    }   
}

//递归中序遍历
void Inorder_recur(Bitree root, int* res, int* returnSize) {
    if (root != NULL) {
        Inorder_recur(root->left, res, returnSize);
        res[*(returnSize)++] = root->val;
        Inorder_recur(root->right, res, returnSize);
    }
}

int main() {
    int tree[N] = {1,2,3,4,5,6,7,8,9,10};
    Bitree root = ToLink(tree, N);
    int res[N];
    int *returnSize = 0;
    Preorder_recur(root, res, returnSize);
    for (int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }



    return 0;
}