//������ǰ�������ͳһ����д��
//LeetCode������Ŀ:144.��������ǰ�������94.�����������������145.�������ĺ������
//��Ƿ���Ҫ����Ľڵ����ջ֮�󣬽����ŷ���һ����ָ����Ϊ���

#include <iostream>
using namespace std;
#include <vector>
#include<stack>

//����������ڵ�
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//����ǰ�����
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
                if (node->right != NULL) st.push(node->right);     //��
                if (node->left != NULL) st.push(node->left);   //��
                st.push(node);  //��
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

//�����������
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
                if (node->right != NULL) st.push(node->right);  //��
                st.push(node);  //��
                st.push(NULL);
                if (node->left != NULL) st.push(node->left);    //��
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

//�����������
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