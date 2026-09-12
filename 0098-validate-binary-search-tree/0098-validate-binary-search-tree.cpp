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
    bool checkBST(TreeNode* root,long long lower,long long upper){
        if(!root){
            return true;
        }
        if(root->val <= lower || root->val >= upper){
            return false;
        }
        return checkBST(root->left,lower,root->val) && checkBST(root->right,root->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        return checkBST(root,LLONG_MIN,LLONG_MAX);
    }
};