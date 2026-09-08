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
    int height(int &diameter, TreeNode* root){
        if(!root){
            return 0;
        }
        int left = height(diameter,root->left);
        int right = height(diameter,root->right);
        diameter = max(diameter, left+right);

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        height(diameter,root);
        return diameter;
    }
};