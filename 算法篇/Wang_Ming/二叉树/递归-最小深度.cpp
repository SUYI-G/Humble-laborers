class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root -> left && root -> right) return 1 + min(minDepth(root -> left), minDepth(root -> right));
        if (root -> left) return 1 + minDepth(root -> left);
        if (root -> right) return 1 + minDepth(root -> right);
        return 1; 

    }
};