/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        while(root){
            if(root == p || root == q){
                return root;
            }else if(root->val < min(p->val,q->val)){
                root = root->right;
            }else if(root->val > max(q->val,p->val)){
                root = root->left;
            }else{
                return root;
            }
        }
        return NULL;
    }
};