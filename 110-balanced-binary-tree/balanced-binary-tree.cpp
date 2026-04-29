
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // base case
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1; // leaf node

            int lh = maxDepth(root->left); 
            int rh =maxDepth(root->right);
            if(lh ==-1 || rh==-1) return -1;

        if (abs(lh - rh) > 1)
            return -1;
        return 1 + max(lh, rh);

    }
    bool isBalanced(TreeNode* root) {

         return maxDepth(root) != -1;
    }
};