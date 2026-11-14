class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }

                prev = curr;
                curr = curr->right;
            } 
            else {
                TreeNode* pred = curr->left;

                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } 
                else {
                    pred->right = nullptr;

                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }

                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if (first && second)
            swap(first->val, second->val);
    }
};
