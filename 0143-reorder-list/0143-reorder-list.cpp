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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return ;
        }
        vector<int>arr;
        ListNode* curr =head;
        
        while(curr != nullptr){
            arr.push_back(curr->val);
            curr =  curr->next;
        }

        int i =0;
        int j = arr.size()-1;
        vector<int>ans;
        while(i <= j){
            if(i == j){
                ans.push_back(arr[i]);
            }
            else{
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
            i++;
            j--;
        }
        curr= head;
        int k =0;

        while(curr != nullptr && k < ans.size()){
            curr->val = ans[k];
            curr = curr->next;
            k++;
        }
    }
};