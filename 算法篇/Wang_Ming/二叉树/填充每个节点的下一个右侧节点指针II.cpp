class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for (int i = 0; i < size - 1; i++){
                Node* cur = que.front();
                que.pop();
                cur -> next = que.front();
                if (cur -> left) que.push(cur -> left);
                if (cur -> right) que.push(cur -> right);
            }
            Node* cur =que.front();
            que.pop();
            if (cur -> left) que.push(cur -> left);
            if (cur -> right) que.push(cur -> right);
        }
        return root;
    }
};