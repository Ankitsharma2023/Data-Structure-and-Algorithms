bool check(TreeNode* p, TreeNode* q) {

      if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
        
    if (p->val != q->val)
        return false;
  

    return check(p->left, q->right) && check(p->right, q->left);
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* p = root->left;
        TreeNode* q = root->right;
        return check(p, q);
    }
};