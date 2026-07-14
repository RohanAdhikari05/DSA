/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)
            return {};
        stack<TreeNode*> st;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            st.push(q.front());
            q.pop();
            if (temp == NULL) {
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                if (temp->right) {
                    q.push(temp->right);
                }
                if (temp->left) {
                    q.push(temp->left);
                }
            }
        }
        st.pop();
        vector<int> temp;
        vector<vector<int>> res;
        while (!st.empty()) {
            if (st.top()) {
                temp.push_back(st.top()->val);
            } else {
                res.push_back(temp);
                temp.clear();
            }
            st.pop();
        }
        if (!temp.empty())
            res.push_back(temp);
        return res;
    }
};