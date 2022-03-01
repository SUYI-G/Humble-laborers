//111.二叉树的最小深度
//给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明：叶子节点是指没有子节点的节点。
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：2

#include <iostream>
using namespace std;
#include<queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//递归法
class Solution_recursion {
public:
    int getDepth(TreeNode* cur) {
        if (cur == NULL) return 0;
        int depthLeft = getDepth(cur->left);
        int depthRight = getDepth(cur->right);
        if (cur->left == NULL && cur->right != NULL) return 1 + depthRight;  //左节点为空，右节点不为空，此时不是最低点
        if (cur->left != NULL && cur->right == NULL) return 1 + depthLeft;   //右节点为空，左节点不为空，此时不是最低点
        return 1 + min(depthLeft, depthRight);
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return getDepth(root);
    }
};
//精简版
class Solution_simplified {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right != NULL) {
            return 1 + minDepth(root->right);
        }
        if (root->left != NULL && root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

//迭代法-层序遍历
class Solution_hierarchical_traverse {
public:
    int minDepth(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            result++;
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left == NULL && node->right == NULL) {
                    return result;
                }
                else {
                    if (node->left != NULL) que.push(node->left);
                    if (node->right != NULL) que.push(node->right);
                }
            }
        }
        return result;
    }
};