class Solution {
public:
    int checkBalanced(TreeNode* root) {
        if (!root)
            return 0;

        int l = checkBalanced(root->left);
        if (l == -1) return -1;

        int r = checkBalanced(root->right);
        if (r == -1) return -1;

        if (abs(l - r) > 1)
            return -1;

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        return checkBalanced(root) != -1;
    }
};