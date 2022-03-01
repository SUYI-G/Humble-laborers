//111.����������С���
//����һ�����������ҳ�����С��ȡ�
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
//˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//���룺root = [3, 9, 20, null, null, 15, 7]
//�����2

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

//�ݹ鷨
class Solution_recursion {
public:
    int getDepth(TreeNode* cur) {
        if (cur == NULL) return 0;
        int depthLeft = getDepth(cur->left);
        int depthRight = getDepth(cur->right);
        if (cur->left == NULL && cur->right != NULL) return 1 + depthRight;  //��ڵ�Ϊ�գ��ҽڵ㲻Ϊ�գ���ʱ������͵�
        if (cur->left != NULL && cur->right == NULL) return 1 + depthLeft;   //�ҽڵ�Ϊ�գ���ڵ㲻Ϊ�գ���ʱ������͵�
        return 1 + min(depthLeft, depthRight);
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return getDepth(root);
    }
};
//�����
class Solution_simplified {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right != NULL) {
            return 1 + minDepth(root->right);
        }
        if (root->left != NULL && root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

//������-�������
class Solution_hierarchical_traverse {
public:
    int minDepth(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> que;
        if (root == NULL) return result;
        else que.push(root);
        while (!que.empty()) {
            int size = que.size();
            result++;
            for (int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left == NULL && node->right == NULL) {
                    return result;
                }
                else {
                    if (node->left != NULL) que.push(node->left);
                    if (node->right != NULL) que.push(node->right);
                }
            }
        }
        return result;
    }
};