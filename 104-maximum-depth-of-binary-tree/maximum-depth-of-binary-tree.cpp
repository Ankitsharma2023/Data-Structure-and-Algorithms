
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //leaf node 
        if(root==nullptr) return 0;
        if(root->left ==NULL && root->right ==nullptr) return 1; 
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1+ max(lh,rh);
    }
};