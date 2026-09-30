class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 1; //number of nodes
        for (auto& edge: edges) {
            int maxNode = max(edge[0], edge[1]); 
            n = max(n, maxNode); 
        }
        
        vector<int> rep(n + 1);

        for (int i = 1; i <= n; ++i) {
            rep[i] = i; 
        } 

        auto find = [&](int node) {
            while (rep[node] != node) {
                node = rep[node]; 
            }
            return node; 
        };

        auto join = [&](int a, int b) {
            int aRep = find(a); 
            int bRep = find(b); 

            if (aRep != bRep) {
                rep[bRep] = aRep; 
                return true; 
            }
            return false; 
        };
        
        vector<int> res; 
        for (auto& edge: edges) {
            int a = edge[0]; 
            int b = edge[1]; 

            if (!join(a, b)) {
                res = edge;  
            }
        }
        return res; 
    }
};
