/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mpp;
    void buildParent(TreeNode* root,TreeNode* parent){
        if(!root){
            return;
        }
        mpp[root] = parent;
        buildParent(root->left,root);
        buildParent(root->right,root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root,nullptr);

        queue<TreeNode*>q;
        q.push(target);
        int dist =0;
        unordered_set<TreeNode*>s;
        s.insert(target);
        while(!q.empty()){
            if(dist == k){
                break;
            }
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && s.find(curr->left) == s.end()){
                    s.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right && s.find(curr->right) == s.end()){
                    s.insert(curr->right);
                    q.push(curr->right);
                }
                if(mpp[curr] && mpp.find(curr) != mpp.end() && s.find(mpp[curr]) == s.end()){
                    s.insert(mpp[curr]);
                    q.push(mpp[curr]);
                }
            }
            dist++;
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};