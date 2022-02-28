//������ǰ������ĵ���д��
//LeetCode������Ŀ:144.��������ǰ�������94.�����������������145.�������ĺ������

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
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);    //��
            if (node->right) st.push(node->right);  //��
            if (node->left) st.push(node->left);    //��
        }
        return result;
    }
};

//�����������
class Solution_inorder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        TreeNode* cur = root;
        while (!st.empty() || cur != NULL) {
            if (cur != NULL) {
                st.push(cur);   //��
                cur = cur->left;
            }
            else {
                cur = st.top();   //�У������result֮��
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;     //��
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