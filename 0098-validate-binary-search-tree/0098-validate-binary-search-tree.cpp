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
    bool validTree(TreeNode* root,long long lower,long long upper){
        if(!root){
            return true;
        }
        if(root->val <= lower || root->val >= upper ){
            return false;
        }
        return validTree(root->left,lower,root->val) && validTree(root->right,root->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        return validTree(root,LLONG_MIN,LLONG_MAX);
    }
};