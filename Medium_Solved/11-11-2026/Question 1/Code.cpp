class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long low, long long high) {
        if (!node) return true;

        long long val = node->val;

        if (val <= low || val >= high)
            return false;

        return validate(node->left, low, val) &&
               validate(node->right, val, high);
    }
};
