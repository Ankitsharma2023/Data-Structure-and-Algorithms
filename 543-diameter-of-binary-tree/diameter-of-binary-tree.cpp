class Solution {
public:
int diameter = 0;

 int height(TreeNode*root)
 {
    if(root== nullptr) return 0;
    if(root->left==nullptr && root->right==nullptr) return 1;
    int lh = height(root->left);
    int rh = height(root->right);

    diameter = max(diameter,lh+rh); //count the edges
    return 1+ max(lh,rh);
 }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};