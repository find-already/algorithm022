#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>

using namespace std;

// 定义完全二叉树数组
int tree[30] = {3,5,1,6,2,0,8,'n','n',7,4};
// 定义长度
int length = 11;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void createTree(TreeNode **root, int i, int *tree, int length)
{
    if(tree[i] == 'n' || i >= length)
        return;
    *root = new TreeNode(tree[i]);
    createTree(&(*root)->left, 2*i+1, tree, length);
    createTree(&(*root)->right, 2*i+2, tree, length);
}
void midPrintTree(TreeNode *root)
{
    if(root == NULL)
        return;
    midPrintTree(root->left);
    printf("%d ", root->val);
    midPrintTree(root->right);
}
TreeNode* findTreeNode(TreeNode *root, int v)
{
    if(root == NULL) {
        return NULL;
    }
    if (root->val == v) {
        return root;
    } else {
        TreeNode* node = findTreeNode(root->left, v);
        if (node)
            return node;
        return findTreeNode(root->right, v);
    }
}


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p || root == q)
            return root;

        TreeNode* left =  lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        if(left && right)
            return root;

        return NULL;
    }
};


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
    输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    输出: 3
    解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
    */
    //构造二叉树
    TreeNode* node_root = NULL, *node_p = NULL, *node_q = NULL;
    createTree(&node_root, 0, tree, 11);
    int val_p = 5, val_q = 1;
    midPrintTree(node_root);
    printf("\n");

    //确定待查找的 node
    node_p = findTreeNode(node_root, 5);
    node_q = findTreeNode(node_root, 1);

    //求最近共同祖先
    Solution solution;
    TreeNode* node = solution.lowestCommonAncestor(node_root, node_p, node_q);
    if (node != NULL) {
        printf("node value = %d \n", node->val);
    }
    return 0;
}