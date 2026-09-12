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
    unordered_map<int,pair<int,int>>mpp;
    void buildMap(TreeNode* root, TreeNode* parent, int lev){
        queue<pair<pair<TreeNode*,TreeNode*>,int>>q;
        q.push({{root,nullptr},0});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front().first.first;
                TreeNode* parent = q.front().first.second;
                int level = q.front().second;
                q.pop();
                if(parent != nullptr){
                    mpp[curr->val] = {level,parent->val};
                }     

                if(curr->left){
                    q.push({{curr->left,curr},level+1});
                }
                if(curr->right){
                    q.push({{curr->right,curr},level+1});
                }
            }
        }

    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root){
            return false;
        }
        buildMap(root,NULL,0);

        int levelX = 0;
        int levelY =0;
        int parentX =0;
        int parentY = 0;

        for(auto p : mpp){
            if(p.first == x){
                levelX = p.second.first;
                parentX = p.second.second;
            }
            if(p.first == y){
                levelY= p.second.first;
                parentY = p.second.second;
            }
        }
        
        if(levelX == levelY && parentX != parentY){
            return true;
        }
        return false;
    }
};