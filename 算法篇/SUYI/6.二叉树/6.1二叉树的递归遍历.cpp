//二叉树前后中序的递归写法
//LeetCode三道题目:144.二叉树的前序遍历、145.二叉树的后序遍历、94.二叉树的中序遍历

#include <iostream>
using namespace std;
#include <vector>

//定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//递归前序遍历
class Solution_preorder {
public:
    void traversal_preorder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    //中
        traversal_preorder(cur->left, vec);   //左
        traversal_preorder(cur->right, vec);  //右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal_preorder(root, result);
        return result;
    }
};

//递归中序遍历
class Solution_inorder {
public:
    void traversal_inorder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal_inorder(cur->left, vec);   //左
        vec.push_back(cur->val);    //中
        traversal_inorder(cur->right, vec);  //右
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal_inorder(root, result);
        return result;
    }
};

//递归后序遍历
class Solution_postorder {
public:
    void traversal_postorder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal_postorder(cur->left, vec);    //左
        traversal_postorder(cur->right, vec);   //右
        vec.push_back(cur->val);    //中
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal_postorder(root, result);
        return result;
    }
};