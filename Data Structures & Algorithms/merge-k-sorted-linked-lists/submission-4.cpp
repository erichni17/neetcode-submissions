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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); 
        if (n == 0) return nullptr; 

        for (int gap = 1; gap < n; gap *= 2) {
            for (int i = 0; i + gap < n; i += 2 * gap) {
                lists[i] = mergeTwoLists(lists[i], lists[i+gap]); 
            }
        }

        return lists[0]; 
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy; 

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next; 
            } else {
                tail->next = b;
                b = b->next; 
            }
            tail = tail->next;
        }

        tail->next = a ? a : b; 
        return dummy.next; 
    }
};
