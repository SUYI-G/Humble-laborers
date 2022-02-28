class Solution {
private:
    bool compare(TreeNode*node1, TreeNode*node2){
        if(node1 == nullptr && node2 == nullptr) return true;
        if(node1 == nullptr || node2 == nullptr) return false;
        if (node1 -> val != node2 -> val) return false;
        if (!compare(node1 -> left, node2 -> right)) return false;
        if (!compare(node1 -> right, node2 -> left)) return false;
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return compare(root, root);

    }
};