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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int>arr;
        ListNode* curr = head;
        if(curr == nullptr || curr->next == nullptr){
            return curr;
        }

        while(curr != nullptr){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        stack<int>st;
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }

        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]] > 1){
                continue;
            }else{
                st.push(arr[i]);
            }
        }
        ListNode* dummy =nullptr;

        while(!st.empty()){
            int x = st.top();
            ListNode* node = new ListNode(x);
            node->next = dummy;
            dummy = node;
            st.pop();
        }
        return dummy;

    }
};