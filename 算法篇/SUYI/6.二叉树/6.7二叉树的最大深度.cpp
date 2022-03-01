//104. 二叉树的最大深度
//LeetCode的2道题目：104.二叉树的最大深度、559. N 叉树的最大深度

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

//104. 二叉树的最大深度
//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//说明 : 叶子节点是指没有子节点的节点。
//示例：给定二叉树[3, 9, 20, null, null, 15, 7]，返回它的最大深度 3 。

//递归法-后序遍历
class Solution_recursion_postorder {
public:
    int getDepth(TreeNode* cur) {
        if (cur == NULL) return 0;
        int leftDepth = getDepth(cur->left);    //左
        int rightDepth = getDepth(cur->right);      //右
        int depth = 1 + max(leftDepth, rightDepth);     //中
        return depth;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return getDepth(root);
    }
};
//精简版代码
class solution1_simplified {
public:
    int maxdepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }
};

//递归法-前序遍历
class Solution_recursion_preorder {
public:
    int result;
    void getDepth(TreeNode* cur, int depth) {
        result = depth > result ? depth : result;   //中
        if (cur->left == NULL && cur->right == NULL) return;
        if (cur->left != NULL) getDepth(cur->left, depth + 1);     //左
        if (cur->right != NULL) getDepth(cur->right, depth + 1);   //右
        return;
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == NULL) return result;
        getDepth(root, 1);   //注意这里是1
        return result;
    }
};

//迭代法-层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            result++;
            int size = que.size();
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
        }
        return result;
    }
};

//559. N 叉树的最大深度
//给定一个 N 叉树，找到其最大深度。
//最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
//N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
//输入：root = [1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null,
//9, 10, null, null, 11, null, 12, null, 13, null, null, 14]
//输出：5

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//递归法
class Solution_recursion {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int result = 0;
        for (int i = 0;i < root->children.size();i++) {
            result = max(result, maxDepth(root->children[i]));
        }
        return result + 1;
    }
};

//迭代法-层序遍历
class Solution_hierarchical_traverse {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        int result = 0;
        if (root == NULL) return result;
        que.push(root);
        while (!que.empty()) {
            result++;
            int size = que.size();
            for (int i = 0;i < size;i++) {
                Node* node = que.front();
                que.pop();
                for (int j = 0;j < node->children.size();j++) {
                    if (node->children[j] != NULL) que.push(node->children[j]);
                }
            }
        }
        return result;
    }
};