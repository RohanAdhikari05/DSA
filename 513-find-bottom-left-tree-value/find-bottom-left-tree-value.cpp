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
    void solve(TreeNode* root, stack<int>& ans,int level){
        if(!root)return;
        if(level == ans.size()){
            ans.push(root->val);
        }
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        stack<int>ans;
        solve(root,ans,0);
        return ans.top(); 
    }
};