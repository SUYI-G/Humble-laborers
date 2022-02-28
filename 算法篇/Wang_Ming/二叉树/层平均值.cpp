class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<TreeNode*>que;
        if (root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            double sum_value = 0.0;
            for (int i = 0; i < size; i++){
                TreeNode*cur = que.front();
                que.pop();
                sum_value += cur -> val;
                if (cur -> left) que.push(cur -> left);
                if (cur -> right) que.push(cur -> right);
            }
            res.push_back(sum_value/size);
        }
        return res;
    }
};