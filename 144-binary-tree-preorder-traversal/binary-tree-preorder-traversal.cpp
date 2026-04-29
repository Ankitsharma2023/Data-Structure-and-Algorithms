class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>st;
        vector<int>res;
        st.push(root);
        if(root==nullptr) return {};

        while(!st.empty())
        {
            TreeNode*node = st.top();
            st.pop();
            res.push_back(node->val);

           if(node->right) st.push(node->right);
           if(node->left) st.push(node->left);
        }
      return res;
    }
};