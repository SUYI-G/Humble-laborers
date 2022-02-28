class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            int max_value = INT_MIN;
            for (int i = 0; i < size; i++){
                TreeNode*cur = que.front();
                que.pop();
                max_value = max(cur->val, max_value);
                if (cur -> left) que.push(cur -> left);
                if (cur -> right) que.push(cur -> right);
            }
            res.push_back(max_value);
        }
        return res;

    }
};