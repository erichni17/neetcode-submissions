/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; 
        unordered_map<Node*, Node*> visited; 
        
        visited[node] = new Node(node->val); 
        queue<Node*> q; 
        q.push(node); 

        while (!q.empty()) {
            Node* curr = q.front(); 
            q.pop(); 
            for (Node* neighbor : curr->neighbors) {
            // ??? — your job: for each neighbor, if it hasn't been
            // cloned yet, clone it and push it to the queue.
            // Then, either way, append the neighbor's clone to
            // visited[curr]'s neighbor list.
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val); 
                    q.push(neighbor); 
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node]; 
    }
};
