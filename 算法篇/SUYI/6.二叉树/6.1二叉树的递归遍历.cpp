//������ǰ������ĵݹ�д��
//LeetCode������Ŀ:144.��������ǰ�������145.�������ĺ��������94.���������������

#include <iostream>
using namespace std;
#include <vector>

//����������ڵ�
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//�ݹ�ǰ�����
class Solution_preorder {
public:
    void traversal_preorder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    //��
        traversal_preorder(cur->left, vec);   //��
        traversal_preorder(cur->right, vec);  //��
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal_preorder(root, result);
        return result;
    }
};

//�ݹ��������
class Solution_inorder {
public:
    void traversal_inorder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal_inorder(cur->left, vec);   //��
        vec.push_back(cur->val);    //��
        traversal_inorder(cur->right, vec);  //��
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal_inorder(root, result);
        return result;
    }
};

//�ݹ�������
class Solution_postorder {
public:
    void traversal_postorder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal_postorder(cur->left, vec);    //��
        traversal_postorder(cur->right, vec);   //��
        vec.push_back(cur->val);    //��
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal_postorder(root, result);
        return result;
    }
};