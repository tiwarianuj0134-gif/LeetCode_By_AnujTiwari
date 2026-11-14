class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        int sum = 0;

        if (root->left) {
            TreeNode* node = root->left;

            if (!node->left && !node->right)
                sum += node->val;
            else
                sum += sumOfLeftLeaves(node);
        }

        if (root->right)
            sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};