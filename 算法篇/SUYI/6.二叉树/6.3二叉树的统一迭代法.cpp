//二叉树前后中序的统一迭代写法
//LeetCode三道题目:144.二叉树的前序遍历、94.二叉树的中序遍历、145.二叉树的后序遍历
//标记法：要处理的节点放入栈之后，紧接着放入一个空指针作为标记

#include <iostream>
using namespace std;
#include <vector>
#include<stack>

//定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//迭代前序遍历
class Solution_preorder {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right != NULL) st.push(node->right);     //右
                if (node->left != NULL) st.push(node->left);   //左
                st.push(node);  //中
                st.push(NULL);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

//迭代中序遍历
class Solution_inorder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL)   return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right != NULL) st.push(node->right);  //右
                st.push(node);  //中
                st.push(NULL);
                if (node->left != NULL) st.push(node->left);    //左
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

//迭代后序遍历
class Solution_postorder {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);
                st.push(NULL);
                if (node->right != NULL) st.push(node->right);
                if (node->left != NULL) st.push(node->left);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};