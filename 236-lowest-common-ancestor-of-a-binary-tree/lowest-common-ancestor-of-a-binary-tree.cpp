// simple make root->path node and check upto their latest connection
class Solution {
public:
    bool findpath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr)
            return false;
        path.push_back(root);

        if (root == target)
            return true;
        ;
        if (findpath(root->left, target, path) ||
            findpath(root->right, target, path))
            return true;
            //retreival of going back
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pp;
        vector<TreeNode*> pq;
        findpath(root, p, pp);
        findpath(root, q, pq);

        // return type TreeNode
        TreeNode* lca = nullptr;
        for (int i = 0; i < min(pp.size(), pq.size()); i++) {
            if (pp[i] == pq[i])
                lca = pp[i];
            else
                break;
        }
        return lca;
    }
};