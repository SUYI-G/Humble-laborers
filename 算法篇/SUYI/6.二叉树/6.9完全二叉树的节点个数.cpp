//222. 完全二叉树的节点个数
//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
//完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，
//其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
//若最底层为第 h 层，则该层包含 1~2h 个节点。
//输入：root = [1, 2, 3, 4, 5, 6]
//输出：6

#include <iostream>
using namespace std;
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//普通二叉树-递归法
class Solution1_recursion {
public:
    int getNodeNum(TreeNode* cur) {
        if (cur == NULL) return 0;
        int numLeft = getNodeNum(cur->left);  //左
        int numRight = getNodeNum(cur->right);    //右
        int num = 1 + numLeft + numRight;     //中（加上中间节点）
        return num;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return (getNodeNum(root));
    }
};
//精简版
class Solution1_simplified {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

//普通二叉树-迭代法-层序遍历
class Solution1_iteration {
public:
    int countNodes(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0;i < size;i++) {
                result++;
                TreeNode* node = que.front();
                que.pop();
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
        }
        return result;
    }
};

//完全二叉树-递归法
//利用完全二叉树的性质
//完全二叉树只有两种情况，情况一：就是满二叉树，情况二：最后一层叶子节点没有满。
//对于情况一，可以直接用 2 ^ 树深度 - 1 来计算，注意这里根节点深度为1。
//对于情况二，分别递归左孩子，和右孩子，递归到某一深度一定会有左孩子或者右孩子为满二叉树，然后依然可以按照情况1来计算。
class Solution2_recursion {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left != NULL) {
            left = left->left;
            leftHeight++;
        }
        while (right != NULL) {
            right = right->right;
            rightHeight++;
        }
        if (leftHeight == rightHeight) return (2 << leftHeight) - 1;  //满二叉树的情况
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};