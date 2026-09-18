/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* formBST(vector<int>& preorder,int& idx,int lower,int upper){
        if(idx >= preorder.size()){
            return nullptr;
        }
        
        if(lower > preorder[idx] || upper < preorder[idx]){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        root->left = formBST(preorder,idx,lower,root->val);
        root->right = formBST(preorder,idx,root->val,upper);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx =0;
        return formBST(preorder,idx,INT_MIN,INT_MAX);
    }
};