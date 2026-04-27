
class Solution {
public:
    void preorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            result.push_back(INT_MIN); 
            return;
        }

        result.push_back(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> vp, vq;
        preorder(p, vp);
        preorder(q, vq);
        return vp == vq;
    }
};