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
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};