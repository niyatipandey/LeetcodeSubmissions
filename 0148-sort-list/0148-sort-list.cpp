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
    ListNode* mergeSort(ListNode* left , ListNode* right){
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(left != nullptr && right != nullptr){
            if(left->val <= right->val){
                curr->next = left;
                left = left->next;
            }else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        while(left != nullptr){
            curr->next = left;
            left = left->next;
            curr = curr->next;
        }
        while(right != nullptr){
            curr->next = right;
            right = right->next;
            curr = curr->next;
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* curr = head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rightHead = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(curr);
        ListNode* right = sortList(rightHead);

        return mergeSort(left,right);
    }
};