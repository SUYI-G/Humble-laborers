//226. ��ת������
//����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
//���룺root = [4, 2, 7, 1, 3, 6, 9]
//�����[4, 7, 2, 9, 6, 3, 1]

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

//����ʹ�õݹ�������ǰ�򡢺����Լ�������������ԣ������ݹ����������ὫĳЩ�ڵ㷭ת2�Σ�
//������ͳһд������������ǿ��Ե�

//�ݹ鷨-ǰ��
class Solution_recursion_preorder {
public:
    void Traversal(TreeNode* cur) {
        if (cur == NULL) return;
        swap(cur->left, cur->right);    //�У��������ҽڵ�
        Traversal(cur->left);   //��
        Traversal(cur->right);  //��
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        else Traversal(root);
        return root;
    }
};

//�ݹ鷨-�����ϸ���˵��������
class Solution {
public:
    void Traversal(TreeNode* cur) {
        if (cur == NULL) return;
        Traversal(cur->left);   //��
        swap(cur->left, cur->right);  //�У��������ҽڵ㣬��ʱ��δ�������ҽڵ��Ϊ��ڵ�
        Traversal(cur->left);    //��(ԭ�����ҽڵ�)
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        else Traversal(root);
        return root;
    }
};

//�ݹ鷨-����
class Solution_recursion_postorder {
public:
    void Traversal(TreeNode* cur) {
        if (cur == NULL) return;
        Traversal(cur->left);   //��
        Traversal(cur->right);    //��
        swap(cur->left, cur->right);  //�У��������ҽڵ�
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        else Traversal(root);
        return root;
    }
};

//������-ǰ��
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
                st.push(node);  //��
                st.push(NULL);
                if (node->left != NULL) st.push(node->left);  //��
                if (node->right != NULL) st.push(node->right);    //��
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

//������-����
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
                if (node->left != NULL) st.push(node->left);   //��
                st.push(node);  //��
                st.push(NULL);
                if (node->right != NULL) st.push(node->right);  //��
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

//������-����
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
                if (node->left != NULL) st.push(node->left);   //��
                if (node->right != NULL) st.push(node->right);  //��
                st.push(node);  //��
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

//������ȱ���
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