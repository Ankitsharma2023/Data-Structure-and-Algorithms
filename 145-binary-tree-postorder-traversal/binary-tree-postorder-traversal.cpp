// simply take 2 stack and push the left and right of node, after that push that node into stack 2
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>s1,s2;
        if(root==nullptr) return {};
         s1.push(root);
         vector<int>ans;

        while(!s1.empty())
        {
            TreeNode*node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }

        while(!s2.empty())
        {
            TreeNode*node = s2.top();
            s2.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};