class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*>que;
        if(root) que.push(root);
        
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode*node=que.front();
                if(node->left||node->right) swap(node->left,node->right);
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

        }
        return root;
    }
};