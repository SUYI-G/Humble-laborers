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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int>res;
        // st.push(root);
        TreeNode*cur = root;
        while(!st.empty() || cur != nullptr){
            if (cur != nullptr){
                st.push(cur);
                st.push(nullptr);
                cur = cur -> left;
            }
            else{
                st.pop();
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur -> right;
            }
        }
        return res;
    }
};