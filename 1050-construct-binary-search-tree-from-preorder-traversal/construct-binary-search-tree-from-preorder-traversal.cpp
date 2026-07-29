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
    void solve(TreeNode* root, int x) {
        while (root) {
            if (root->val < x) {
                if (root->right)
                    root = root->right;
                else
                    break;
            } else {
                if (root->left)
                    root = root->left;
                else
                    break;
            }
        }
        TreeNode* newNode = new TreeNode(x);
        if (x > root->val) {
            root->right = newNode;
        } else {
            root->left = newNode;
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (!preorder.size())
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            solve(root, preorder[i]);
        }
        return root;
    }
};