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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool leftToRight = true;

        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            vector<int>arr;
            int n =q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                int x = node->val;
                q.pop();
                arr.push_back(x);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(leftToRight == false){
                reverse(arr.begin(),arr.end());
            }
            ans.push_back(arr);
            leftToRight = !leftToRight;
        }
        return ans;

    }
};