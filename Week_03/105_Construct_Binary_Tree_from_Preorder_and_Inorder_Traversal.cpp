#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};

void midPrintTree(TreeNode *root)
{
    if(root == NULL)
        return;
    midPrintTree(root->left);
    printf("%d ", root->val);
    midPrintTree(root->right);
}

int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        前序遍历 preorder = [3,9,20,15,7]
        中序遍历 inorder = [9,3,15,20,7]
    */
    Solution solution;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = solution.buildTree(preorder, inorder);
    if (root != NULL) {
        midPrintTree(root);
        printf("\n");
    }
    return 0;
}