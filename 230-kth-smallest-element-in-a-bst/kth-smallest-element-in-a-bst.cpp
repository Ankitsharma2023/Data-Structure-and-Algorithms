
class Solution {
public:
   
    vector<int>inorder(TreeNode*root, vector<int>&ans)
    {
        if(root==nullptr) return {};

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        int res= ans[k-1];
        return res;
    }
};