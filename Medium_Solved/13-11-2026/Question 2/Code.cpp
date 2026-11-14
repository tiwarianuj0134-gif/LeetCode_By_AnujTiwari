class Solution {
    unordered_map<int, int> pos;
    int idx;

    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right)
            return nullptr;

        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);

        int mid = pos[val];

        root->right = build(postorder, mid + 1, right);
        root->left = build(postorder, left, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        pos.reserve(n);
        pos.max_load_factor(0.7f);

        for (int i = 0; i < n; ++i)
            pos[inorder[i]] = i;

        idx = n - 1;

        return build(postorder, 0, n - 1);
    }
};
