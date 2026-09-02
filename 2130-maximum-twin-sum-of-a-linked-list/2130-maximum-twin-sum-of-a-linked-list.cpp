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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevPtr = nullptr;
        ListNode* curr = head;

        while(fast != nullptr && fast->next != nullptr){
            prevPtr = slow;
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* prev =nullptr;
        ListNode* temp = slow;
        while(slow != nullptr){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        int maxSum = INT_MIN;

        while(prev != nullptr && curr != prev ){
            int left = curr->val;
            int right = prev->val;

            maxSum = max(maxSum, left+right);
            curr = curr->next;
            prev = prev->next;
        }
        return maxSum;
    }
};