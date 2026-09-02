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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev= nullptr;
        ListNode* leftPtr = head;
        ListNode* rightPtr = head;
        ListNode* prevPtr = head;
        int leftVal = left;
        int rightVal = right;

        while(leftVal-1 > 0){
            prevPtr = leftPtr;
            leftPtr = leftPtr->next;
            leftVal--;
        }
        while(rightVal-1 > 0){
            rightPtr = rightPtr->next;
            rightVal--;
        }
        ListNode* after = rightPtr->next;
        ListNode* curr = leftPtr;
        ListNode* temp = leftPtr;

        while(curr != after){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        leftPtr->next = after; 
        if(left == 1){
            return prev;
        }
        prevPtr->next = prev;
        return head;
    }
};