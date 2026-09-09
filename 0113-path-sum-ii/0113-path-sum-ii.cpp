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
    void sumOfPath(TreeNode* root,int targetSum, int sum ,vector<int>&vals, vector<vector<int>>&ans){
        if(!root->left && !root->right){
            if(sum == targetSum){
                ans.push_back(vals);
            }
            return;
        }
        int leftVal = 0;
        int rightVal = 0;
        if(root->left){
            leftVal = root->left->val;
        }
        if(root->right){
            rightVal = root->right->val;
        }
        if(root->left){
            vals.push_back(leftVal);
            sumOfPath(root->left,targetSum, sum + leftVal ,vals, ans);
            vals.pop_back();
        }
        if(root->right){
            vals.push_back(rightVal);
            sumOfPath(root->right,targetSum, sum + rightVal ,vals, ans);
            vals.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>vals;
        vector<vector<int>>ans;

        if(!root){
            return ans;
        }
        vals.push_back(root->val);
        int sum = root->val;

        sumOfPath(root,targetSum, sum ,vals, ans);

        return ans;
    }
};