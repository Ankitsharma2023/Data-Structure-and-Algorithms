class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* IP = curr->left;
                while (IP->right != nullptr && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == nullptr) {
                    // create connection
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = nullptr;
                    ans.push_back(curr->val); // left root right
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};