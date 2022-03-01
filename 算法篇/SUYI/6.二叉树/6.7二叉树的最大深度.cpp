//104. ��������������
//LeetCode��2����Ŀ��104.�������������ȡ�559. N ������������

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

//104. ��������������
//����һ�����������ҳ��������ȡ�
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//ʾ��������������[3, 9, 20, null, null, 15, 7]���������������� 3 ��

//�ݹ鷨-�������
class Solution_recursion_postorder {
public:
    int getDepth(TreeNode* cur) {
        if (cur == NULL) return 0;
        int leftDepth = getDepth(cur->left);    //��
        int rightDepth = getDepth(cur->right);      //��
        int depth = 1 + max(leftDepth, rightDepth);     //��
        return depth;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return getDepth(root);
    }
};
//��������
class solution1_simplified {
public:
    int maxdepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }
};

//�ݹ鷨-ǰ�����
class Solution_recursion_preorder {
public:
    int result;
    void getDepth(TreeNode* cur, int depth) {
        result = depth > result ? depth : result;   //��
        if (cur->left == NULL && cur->right == NULL) return;
        if (cur->left != NULL) getDepth(cur->left, depth + 1);     //��
        if (cur->right != NULL) getDepth(cur->right, depth + 1);   //��
        return;
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == NULL) return result;
        getDepth(root, 1);   //ע��������1
        return result;
    }
};

//������-�������
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

//559. N ������������
//����һ�� N �������ҵ��������ȡ�
//��������ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�������
//N �������밴����������л���ʾ��ÿ���ӽڵ��ɿ�ֵ�ָ�����μ�ʾ������
//���룺root = [1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null,
//9, 10, null, null, 11, null, 12, null, 13, null, null, 14]
//�����5

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

//�ݹ鷨
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

//������-�������
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