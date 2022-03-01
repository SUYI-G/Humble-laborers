//101. �Գƶ�����
//����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�

#include <iostream>
using namespace std;
#include<queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//�ݹ鷨��ֻ���ú���
class Solution_recursion {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left != NULL && right != NULL && left->val != right->val) return false; //ע����else if����Ϊ����һ�������left=right�Ҷ���ΪNULL���ͽ��ŵݹ�
        //else return compare(left->left, right->right) && compare(left->right, right->left);  //����Ϊ����4�еľ����
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool result = outside && inside;
        return result;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        else return compare(root->left, root->right);
    }
};

//������-ʹ�ö��У�ջҲ���ԣ�ԭ�ⲻ���ĳ�ջ���ɣ�
class Solution_iteration {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == NULL) return true;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();
            if (left == NULL && right == NULL) continue;    //���ҽڵ㶼Ϊ��
            if (!left || !right || (left->val != right->val)) return false;  //����һ���ڵ㲻Ϊ�գ����߶���Ϊ�յ���ֵ����ͬ
            //if (left==NULL || right==NULL || (left->val != right->val)) return false;     //������һ��Ч����ͬ
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};