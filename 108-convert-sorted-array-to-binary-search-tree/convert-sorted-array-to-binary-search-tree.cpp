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
    void solve(vector<int>& nums,TreeNode* root, int s, int e){
        if(s>e)return;
        int mid = s+(e-s)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        if(nums[mid]>root->val){
            root->right = temp;
        }else{
            root->left = temp;
        }
        solve(nums,temp,s,mid-1);
        solve(nums,temp,mid+1,e);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        solve(nums,root,s,mid-1);
        solve(nums,root,mid+1,e);
        return root;
    }
};