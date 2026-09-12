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
    map<int, vector<pair<int,int>>>mpp;
    void buildMap(TreeNode* root , int val){
        queue<pair<pair<int,TreeNode*>,int>>q;
        q.push({{val,root},0});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front().first.second;
                int data = q.front().first.first;
                int level = q.front().second;
                q.pop();

                mpp[data].push_back({level,curr->val});

                if(curr->left){
                    q.push({{data-1,curr->left},level+1});
                }
                if(curr->right){
                    q.push({{data+1,curr->right},level+1});
                }
            }
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        buildMap(root,0);

        for(auto x : mpp){
            vector<pair<int,int>>arr = x.second;
            sort(arr.begin(),arr.end());
            vector<int>levelArr;
            for(auto ele : arr){
                levelArr.push_back(ele.second);
            }
            ans.push_back(levelArr);
        }
        return ans;
    }
};