//二叉树前后中序的迭代写法
//LeetCode三道题目:144.二叉树的前序遍历、94.二叉树的中序遍历、145.二叉树的后序遍历

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
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);    //中
            if (node->right) st.push(node->right);  //右
            if (node->left) st.push(node->left);    //左
        }
        return result;
    }
};

//迭代中序遍历
class Solution_inorder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        TreeNode* cur = root;
        while (!st.empty() || cur != NULL) {
            if (cur != NULL) {
                st.push(cur);   //左
                cur = cur->left;
            }
            else {
                cur = st.top();   //中（左加入result之后）
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;     //右
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
        if (root == NULL)  return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left != NULL) st.push(node->left);
            if (node->right != NULL)   st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};