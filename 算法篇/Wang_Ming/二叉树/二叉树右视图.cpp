/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if (root) {que.push(root); res.push_back(root -> val);}
        while (!que.empty()){
           bool flag = false;
           int size = que.size();
           for (int i = 0; i < size; i++){
               TreeNode*cur = que.front();
               que.pop();
               if (!flag && (cur -> right || cur -> left)){
                   flag = true;
                   if (cur -> right) res.push_back(cur ->right -> val);
                   else res.push_back(cur -> left -> val);
               }
               if (cur -> right) que.push(cur -> right);
               if(cur -> left) que.push(cur -> left);
           }
        }
        return res;
    }
};