class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses); 
        vector<vector<int>> adj(numCourses);
        queue<int> q; 
        int taken = 0;  

        for (auto& pr : prerequisites) {
            int a = pr[0]; 
            int b = pr[1]; 
            adj[b].push_back(a); 
            indegrees[a]++; 
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q.push(i); 
            }
        }

        while (!q.empty()) {
            int c = q.front(); 
            q.pop();
            taken++; 
            for (int course : adj[c]){
                indegrees[course]--; 
                if (indegrees[course] == 0) {
                    q.push(course); 
                }
            }
        }

        return taken == numCourses; 
    }
};
