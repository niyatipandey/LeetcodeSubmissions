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
    bool findPath(int sum,TreeNode* root, int targetSum){
        if(!root->left && !root->right){
            if(sum == targetSum){
                return true;
            }
        }
        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;
        bool left = false;
        bool right = false;
        if(root->left){
            left = findPath(sum+leftVal,root->left,targetSum);
        }
        if(root->right){
            right = findPath(sum+rightVal,root->right,targetSum);
        }
        
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        int sum = root->val;
        return findPath(sum,root,targetSum);

    }
};