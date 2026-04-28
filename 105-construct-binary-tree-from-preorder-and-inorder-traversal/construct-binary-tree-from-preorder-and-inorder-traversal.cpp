
class Solution {
public:
 unordered_map<int,int>mpp;
    TreeNode*solve(vector<int>&preorder,vector<int>&inorder,int&index,int inorder_start,int inorder_end)
    {
        int n = preorder.size();
        if(index>=n || inorder_start>inorder_end) return nullptr;

        TreeNode*root = new TreeNode(preorder[index]);
        int position = mpp[preorder[index]];
        index++;

        root->left = solve(preorder,inorder,index,inorder_start,position-1);
        root->right = solve(preorder,inorder,index,position+1,inorder_end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //mapping of index of inorder
       
        for(int i =0;i<inorder.size();i++) mpp[inorder[i]] = i;
        int index = 0; //for preorder head is start index
        
        return solve(preorder,inorder,index,0,inorder.size()-1);

    }
};