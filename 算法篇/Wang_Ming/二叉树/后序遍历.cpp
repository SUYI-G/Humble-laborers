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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>vec;
        TreeNode*cur = root;
        while(cur != nullptr || !st.empty()){
            if (cur != nullptr){
                st.push(cur);
                st.push(nullptr);
                if (cur -> right) st.push(cur -> right);
                cur = cur -> left;
            }
            else{
                cur = st.top();
                st.pop();
                if (cur == nullptr){
                    cur = st.top();
                    vec.push_back(cur->val);
                    st.pop();
                    if (st.empty()){
                        cur = nullptr;
                    }else{
                        cur = st.top();
                        if(cur) st.pop();
                    }
                }
            }
            
        }
        return vec;
    }
};