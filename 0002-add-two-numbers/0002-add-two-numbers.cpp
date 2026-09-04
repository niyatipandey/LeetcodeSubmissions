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
        ListNode* l1Head = l1;
        ListNode* l2Head = l2;
        int carry =0;
        ListNode dummy(0);
        ListNode* current = &dummy;

        while(l1Head != nullptr || l2Head!= nullptr){
            int val1 = l1Head ? l1Head->val : 0;
            int val2 = l2Head ? l2Head->val : 0;
            int sum = val1 + val2 + carry;
            ListNode* newHead = new ListNode(sum%10);
            current->next = newHead;
            current = newHead;
            carry = sum / 10;
            if(l1Head){
                l1Head = l1Head->next;
            }
            if(l2Head){
                l2Head = l2Head->next;
            }
        }
        if(carry > 0){
            ListNode* newHead = new ListNode(carry);
            current->next = newHead;
            current = newHead;
        }

        return dummy.next;
    }
};