
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*insert = new TreeNode(val);
       TreeNode*curr = root;//root should not moved as we have to return this at end;
     if(root==NULL) return insert;

        while(curr)
        {
            if(curr->val<val)
            {
                if(curr->right==NULL)
                {
                    curr->right= insert;
                    break;
                }
                curr=curr->right;
            }
            else
            {
                if(curr->left==nullptr)
                {
                    curr->left=insert;
                    break;
                }
                curr=curr->left;
            }
        }

return root;
    }
};
