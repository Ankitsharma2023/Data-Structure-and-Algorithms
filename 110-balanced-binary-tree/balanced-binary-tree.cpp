
class Solution {
public:
    int depth(TreeNode*root)
    {
        if(root==nullptr) return 0;

        if(root->left == nullptr && root->right ==nullptr) return 1;
        int lh = depth(root->left);
        int rh = depth(root->right);
         
         if(lh==-1 || rh==-1) return -1;
         if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        return depth(root)!=-1;
    }
};