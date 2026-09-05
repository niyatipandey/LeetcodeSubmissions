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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = nullptr;
        stack<ListNode*>st1;
        stack<ListNode*>st2;
        ListNode* headL1 = l1;
        ListNode* headL2 = l2;

        while(headL1 != nullptr){
            st1.push(headL1);
            headL1 = headL1->next;
        }
        while(headL2 != nullptr){
            st2.push(headL2);
            headL2 = headL2->next;
        }

        int carry =0;

        while(!st1.empty() && !st2.empty()){
            int valL1 = st1.top()->val;
            int valL2 = st2.top()->val;

            int sum = valL1 + valL2 + carry;
            ListNode* curr = new ListNode(sum%10);
            curr->next = dummy;
            dummy = curr;
            carry = sum/10;
            st1.pop();
            st2.pop();
        }
        while(!st1.empty()){
            int val = st1.top()->val;
            int sum = val+carry;
            ListNode* curr = new ListNode(sum%10);
            curr->next = dummy;
            dummy = curr;
            carry = sum/10;
            st1.pop();
        }
        while(!st2.empty()){
            int val = st2.top()->val;
            int sum = val + carry;
            ListNode* curr = new ListNode(sum%10);
            curr->next = dummy;
            dummy = curr;
            carry = sum/10;
            st2.pop();
        }
        if(carry > 0){
            ListNode* carryPtr = new ListNode(carry);
            carryPtr->next = dummy;
            dummy = carryPtr;
        }
        return dummy;
    }
};