
class Solution {
public:
       int maxDepth(TreeNode* root) {
        
        if(root==nullptr) return 0;
        //leaf node 
        if(root->left ==NULL && root->right ==nullptr) return 1; 
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        if(lh==-1 ||rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;

        return 1+ max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        return maxDepth(root)!=-1;
    }
};