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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(); 
        ListNode* prevGroup = dummy;  
        
        while (head) {
            ListNode* nextGroup;
            ListNode* tail = head;  
            for (int i = 0; i < k - 1; ++i) {
                tail = tail->next;
                if (!tail) break;  
            }
            if (!tail) break; 

            nextGroup = tail->next;

            reverse(head, tail); 

            prevGroup->next = tail;

            head->next = nextGroup; 

            prevGroup = head; 

            head = nextGroup;  
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res; 
    }

    void reverse(ListNode* head, ListNode* tail) {
        if (!head || !tail) return; 
        ListNode* prev = nullptr; 
        ListNode* nextGroup = tail->next;
        
        while (head != nextGroup) {
            ListNode* next = head->next;
            head->next = prev; 
            prev = head;
            head = next;
        }
    }
};
