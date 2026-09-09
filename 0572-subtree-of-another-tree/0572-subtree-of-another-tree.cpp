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
    bool sameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }
        if(!root ||!subRoot){
            return false;
        }

        return root->val == subRoot->val && sameTree(root->left,subRoot->left) && sameTree(root->right,subRoot->right); 
    }
    bool subtree(TreeNode* root, TreeNode* subRoot){
        if(!root){
            return false;
        }
        if(sameTree(root,subRoot)){
            return true;
        }

        bool left = subtree(root->left,subRoot);
        bool right = subtree(root->right,subRoot);

        return left || right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        if(!root ||!subRoot){
            return false;
        }
        return subtree(root,subRoot);
    }
};