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
    TreeNode* nodeToParent(TreeNode* root, int start,
                           map<TreeNode*, TreeNode*>& mp) {
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->val == start) {
                res = temp;
            }
            if (temp->left) {
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return res;
    }
    int infectTree(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;
        int ans = 0;
        while (!q.empty()) {
            bool flag = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left && !visited[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if (front->right && !visited[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if (mp[front] && !visited[mp[front]]) {
                    flag = 1;
                    q.push(mp[front]);
                    visited[mp[front]] = 1;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans;
        map<TreeNode*, TreeNode*> mp;
        TreeNode* target = nodeToParent(root, start, mp);
        ans = infectTree(target, mp);
        return ans;
    }
};