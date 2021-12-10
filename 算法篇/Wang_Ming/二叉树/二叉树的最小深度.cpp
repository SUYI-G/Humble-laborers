class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int Depth = 0;
        while(!que.empty()){
            Depth++;
            int size = que.size();
            for (int i = 0; i < size; i++){
                TreeNode*cur = que.front();
                que.pop();
                if (cur -> left == nullptr && cur -> right == nullptr) return Depth;
                if (cur -> left) que.push(cur -> left);
                if (cur -> right) que.push(cur -> right);
            }
        }
        return Depth;
    }
};