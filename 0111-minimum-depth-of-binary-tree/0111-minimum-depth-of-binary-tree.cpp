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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(!root->left){
            left = INT_MAX;
        }
        if(!root->right){
            right = INT_MAX;
        }
        if(left == INT_MAX && right == INT_MAX){
            return 1;
        }
        
        return min(left,right)+1;
    }
};