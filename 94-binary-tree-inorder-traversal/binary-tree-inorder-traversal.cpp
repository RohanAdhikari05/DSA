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
    void inorder(TreeNode* root, queue<int>& q){
        if(root==NULL)return;
        inorder(root->left,q);
        q.push(root->val);
        inorder(root->right,q);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        queue<int>q;
        vector<int>ans;
        inorder(root,q);
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};