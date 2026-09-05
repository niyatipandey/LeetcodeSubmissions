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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr = head;
        vector<int>arr;

        while(curr != nullptr){
            arr.push_back(curr->val);
            curr = curr->next;
        }

        stack<int>st;
        ListNode* dummy = nullptr;

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            ListNode* curr = new ListNode(arr[st.top()]);
            curr->next = dummy;
            dummy = curr;
            st.pop();
        }
        return dummy;
    }
};