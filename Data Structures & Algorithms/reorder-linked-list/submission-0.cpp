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
        ListNode* fast = head; 
        ListNode* slow = head; 
        
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next; 
        }

        ListNode* l1 = head; 
        ListNode* l2 = slow->next; 

        slow->next = nullptr; 

        ListNode* prev = nullptr; 
        ListNode* curr = l2; 
        
        while (curr) {
            ListNode* next = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = next; 
        }

        l2 = prev; 

        while (l1 && l2) {
            ListNode* nextA = l1->next; 
            ListNode* nextB = l2->next; 
            l1->next = l2; 
            l2->next = nextA; 
            l1 = nextA; 
            l2 = nextB; 
        }
    }
};
