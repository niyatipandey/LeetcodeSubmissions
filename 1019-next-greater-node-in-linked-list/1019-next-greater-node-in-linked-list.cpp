/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>nums;
        ListNode* curr = head;

        while(curr != nullptr){
            nums.push_back(curr->val);
            curr = curr->next;
        }

        vector<int>ans(nums.size(),0);
        unordered_map<int,int>mpp;
        stack<int>st;


        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                mpp[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<nums.size();i++){
            ans[i] = mpp[i];
        }
        return ans;
    }
};