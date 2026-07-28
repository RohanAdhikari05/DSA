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
    vector<int>arr;
    void solve(TreeNode* root){
        if(!root)return;
        arr.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right))return;
        solve(root);
        TreeNode* curr = root;
        for(int i=1; i<arr.size(); i++){
            curr->left = NULL;
            TreeNode* newNode = new TreeNode(arr[i]);
            curr->right = newNode;
            curr = curr->right;
        }
        curr->left = NULL;
        curr->right = NULL;
    }
};