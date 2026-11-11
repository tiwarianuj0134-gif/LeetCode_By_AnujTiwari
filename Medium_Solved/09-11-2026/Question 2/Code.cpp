class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        if (start > end)
            return {nullptr};

        vector<TreeNode*> ans;

        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> left = build(start, rootVal - 1);
            vector<TreeNode*> right = build(rootVal + 1, end);

            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = l;
                    root->right = r;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};
