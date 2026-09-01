/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; 
        unordered_map<Node*, Node*> mp; 
        Node* newHead = new Node(head->val);
        mp[head] = newHead; 
        Node* oldHead = head;   
        Node* curr = newHead; 
        while (head->next) {
            if (!mp.count(head->next)) {
                mp[head->next] = new Node(head->next->val); 
            } 
            head = head->next; 
        }
        while (oldHead) {
            curr->next = mp[oldHead->next];
            curr->random = mp[oldHead->random]; 
            oldHead = oldHead->next;
            curr = curr->next; 
        }
        return newHead; 
    }
};
