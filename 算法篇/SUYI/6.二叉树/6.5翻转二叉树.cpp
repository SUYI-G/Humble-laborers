//226. 翻转二叉树
//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//输入：root = [4, 2, 7, 1, 3, 6, 9]
//输出：[4, 7, 2, 9, 6, 3, 1]

#include <iostream>
using namespace std;
#include<stack>
#include<queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//本题使用递归或迭代的前序、后序以及层序遍历都可以，不过递归的中序遍历会将某些节点翻转2次，
//迭代的统一写法的中序遍历是可以的

//递归法-前序
class Solution_recursion_preorder {
public:
    void Traversal(TreeNode* cur) {
        if (cur == NULL) return;
        swap(cur->left, cur->right);    //中，交换左右节点
        Traversal(cur->left);   //左
        Traversal(cur->right);  //右
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        else Traversal(root);
        return root;
    }
};

//递归法-中序（严格来说不算中序）
class Solution {
public:
    void Traversal(TreeNode* cur) {
        if (cur == NULL) return;
        Traversal(cur->left);   //左
        swap(cur->left, cur->right);  //中，交换左右节点，此时还未遍历的右节点变为左节点
        Traversal(cur->left);    //左(原来的右节点)
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        else Traversal(root);
        return root;
    }
};

//递归法-后序
class Solution_recursion_postorder {
public:
    void Traversal(TreeNode* cur) {
        if (cur == NULL) return;
        Traversal(cur->left);   //左
        Traversal(cur->right);    //右
        swap(cur->left, cur->right);  //中，交换左右节点
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        else Traversal(root);
        return root;
    }
};

//迭代法-前序
class Solution_iteration_preorder {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return root;
        else st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);  //中
                st.push(NULL);
                if (node->left != NULL) st.push(node->left);  //左
                if (node->right != NULL) st.push(node->right);    //右
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
        return root;
    }
};

//迭代法-中序
class Solution_iteration_inorder {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return root;
        else st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->left != NULL) st.push(node->left);   //左
                st.push(node);  //中
                st.push(NULL);
                if (node->right != NULL) st.push(node->right);  //右
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
        return root;
    }
};

//迭代法-后序
class Solution_iteration_postorder {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return root;
        else st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->left != NULL) st.push(node->left);   //左
                if (node->right != NULL) st.push(node->right);  //右
                st.push(node);  //中
                st.push(NULL);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
        return root;
    }
};

//广度优先遍历
class Solution_hierarchical_traverse {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == NULL) return root;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
        }
        return root;
    }
};