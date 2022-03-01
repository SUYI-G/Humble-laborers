//101. 对称二叉树
//给你一个二叉树的根节点 root ， 检查它是否轴对称。

#include <iostream>
using namespace std;
#include<queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归法（只能用后序）
class Solution_recursion {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left != NULL && right != NULL && left->val != right->val) return false; //注意是else if，因为还有一种情况是left=right且都不为NULL，就接着递归
        //else return compare(left->left, right->right) && compare(left->right, right->left);  //此行为后面4行的精简版
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool result = outside && inside;
        return result;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        else return compare(root->left, root->right);
    }
};

//迭代法-使用队列（栈也可以，原封不动改成栈即可）
class Solution_iteration {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == NULL) return true;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();
            if (left == NULL && right == NULL) continue;    //左、右节点都为空
            if (!left || !right || (left->val != right->val)) return false;  //左右一个节点不为空，或者都不为空但数值不相同
            //if (left==NULL || right==NULL || (left->val != right->val)) return false;     //这句和上一行效果相同
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};