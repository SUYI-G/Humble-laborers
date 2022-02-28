//二叉树的层序遍历
//LeetCode的10道题目:102.二叉树的层序遍历、107.二叉树的层次遍历II、199.二叉树的右视图、
//637.二叉树的层平均值、429.N叉树的层序遍历、515.在每个树行中找最大值、
//116.填充每个节点的下一个右侧节点指针、117.填充每个节点的下一个右侧节点指针II、
//104.二叉树的最大深度、111.二叉树的最小深度

#include <iostream>
using namespace std;
#include <vector>
#include<queue>

//定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//102. 二叉树的层序遍历
//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
//（即逐层地，从左到右访问所有节点）。
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出： [[3], [9, 20], [15, 7]]
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

//107. 二叉树的层序遍历 II
//给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。
//（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//输入：root = [3,9,20,null,null,15,7]
//输出： [[15, 7], [9, 20], [3]]
class Solution2 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            result.push_back(vec);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//199. 二叉树的右视图
//给定一个二叉树的 根节点 root，想象自己站在它的右侧，
//按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//输入: [1, 2, 3, null, 5, null, 4]
//输出 : [1, 3, 4]
class Solution3 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == size - 1) result.push_back(node->val);
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
        }
        return result;
    }
};

//637.二叉树的层平均值
//给定一个非空二叉树的根节点 root, 以数组的形式返回每一层节点的平均值。
//与实际答案相差 10 - 5 以内的答案可以被接受。
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：[3.00000, 14.50000, 11.00000]
class Solution4 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double sum = 0;
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                sum = sum + node->val;
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            result.push_back(sum / size);
        }
        return result;
    }
};

//429. N 叉树的层序遍历
//给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
//树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
//输入：root = [1, null, 3, 2, 4, null, 5, 6]
//输出： [[1], [3, 2, 4], [5, 6]]
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
class Solution5 {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0;i < size;i++) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int j = 0;j < node->children.size();j++) {
                    if(node->children[j]!=NULL) que.push(node->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};

//515. 在每个树行中找最大值
//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
//输入: root = [1, 3, 2, 5, 3, null, 9]
//输出 : [1, 3, 9]
class Solution6 {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int max = INT_MIN;
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->val > max) max = node->val;
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            result.push_back(max);
        }
        return result;
    }
};

//116. 填充每个节点的下一个右侧节点指针
//给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//初始状态下，所有 next 指针都被设置为 NULL。
//输入：root = [1, 2, 3, 4, 5, 6, 7]
//输出：[1, #, 2, 3, #, 4, 5, 6, 7, #]
class Node7 {
public:
    int val;
    Node7* left;
    Node7* right;
    Node7* next;

    Node7() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node7(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node7(int _val, Node7* _left, Node7* _right, Node7* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution7 {
public:
    Node7* connect(Node7* root) {
        queue<Node7*> que;
        if (root == NULL) return root;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node7* node;
            Node7* nodePre;
            for (int i = 0;i < size;i++) {
                if (i == 0) {
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }
                else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            nodePre->next = NULL;
        }
        return root;
    }
};

//117. 填充每个节点的下一个右侧节点指针 II
//给定一个二叉树, 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
//如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//初始状态下，所有 next 指针都被设置为 NULL。
class Solution8 {
public:
    Node7* connect(Node7* root) {
        queue<Node7*> que;
        if (root == NULL) return root;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node7* node;
            Node7* nodePre;
            for (int i = 0;i < size;i++) {
                if (i == 0) {
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }
                else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            node->next = NULL;
        }
        return root;
    }
};

//104. 二叉树的最大深度
//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//说明 : 叶子节点是指没有子节点的节点。
//示例：给定二叉树[3, 9, 20, null, null, 15, 7]，返回它的最大深度 3 。
class Solution9 {
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

//111. 二叉树的最小深度
//给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明：叶子节点是指没有子节点的节点。
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：2
class Solution10 {
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