class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        vector<TreeNode*> st;
        st.reserve(100);
        st.push_back(root);

        while (!st.empty()) {
            TreeNode* node = st.back();
            st.pop_back();

            ans.push_back(node->val);

            if (node->right) st.push_back(node->right);
            if (node->left) st.push_back(node->left);
        }

        return ans;
    }
};
