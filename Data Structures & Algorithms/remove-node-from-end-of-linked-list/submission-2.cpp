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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head; 
        for (int i = 0; i < n; ++i) {
            front = front->next; 
        }
        ListNode* back = head;
        ListNode* backPrev = nullptr;  
        while (front) {
            front = front->next;
            backPrev = back;  
            back = back->next; 
        }
        if (backPrev) backPrev->next = back->next;
        else if (head) head = head->next;  
        else head = nullptr; 
        delete back; 
        return head; 
    }
};
