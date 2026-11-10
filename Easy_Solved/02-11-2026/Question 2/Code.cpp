class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;

            size_t oldSize = path.size();

            if (!path.empty()) path += "->";
            path += to_string(node->val);

            if (!node->left && !node->right) {
                ans.push_back(path);
            } else {
                dfs(node->left);
                dfs(node->right);
            }

            path.resize(oldSize);
        };

        dfs(root);
        return ans;
    }
};
