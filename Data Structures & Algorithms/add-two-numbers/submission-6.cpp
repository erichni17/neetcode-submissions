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
        int carry = 0;
        ListNode* dummy = new ListNode(); 
        ListNode* curr = dummy; 
        while (l1 || l2) {
            int currSum = carry;
            if (l1) {
                currSum += l1->val; 
            } 
            if (l2) {
                currSum += l2->val; 
            }
            
            curr->next = new ListNode(currSum % 10);
            curr = curr->next; 

            if (currSum >= 10) {
                carry = 1;  
            } else {
                carry = 0; 
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next; 
        }

        if (carry) {
            curr->next = new ListNode(1); 
        }

        ListNode* head = dummy->next; 
        delete dummy;
        return head; 
    }
};
