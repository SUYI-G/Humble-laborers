class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if (root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++){
                Node* cur = que.front();
                que.pop();
                tmp.push_back(cur -> val);
                for (int j = 0; j < cur -> children.size(); j++){
                    que.push(cur -> children[j]);
                }

            }
            res.push_back(tmp);
        }
        return res;
        
    }
};