class Solution {
    unordered_map<int, int> pos;
    int pre = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;

        int val = preorder[pre++];
        TreeNode* root = new TreeNode(val);

        int mid = pos[val];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        pos.reserve(n);

        for (int i = 0; i < n; ++i)
            pos[inorder[i]] = i;

        return build(preorder, 0, n - 1);
    }
};
