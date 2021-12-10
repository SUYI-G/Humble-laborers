class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> vec;
        if (root) que.push(root);
        else return vec;
        while(!que.empty()){
            int size = que.size();
            vector<int> ceng;
            for (int i = 0; i < size; i++){
                TreeNode*cur = que.front();
                ceng.push_back(cur->val);
                que.pop();
                if (cur -> left) que.push(cur -> left);
                if(cur -> right) que.push(cur -> right);
            }
            vec.push_back(ceng);
        }
        return vec;
    }
};