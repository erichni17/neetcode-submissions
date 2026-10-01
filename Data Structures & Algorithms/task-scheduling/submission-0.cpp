class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq (26); 

        for (char task: tasks) {
            freq[task-'A']++; 
        }

        priority_queue<int> complete; //greedily complete the task with the highest remaining freq
        queue<pair<int, int>> cooldown; //freq, time available

        for (int f : freq) {
            if (f != 0) {
                complete.push(f);
            }
        }

        int time = 0; 
        while (true) {
            if (complete.empty() && cooldown.empty()) break; 
            if (!cooldown.empty()){
                auto [freq, timeAvail] = cooldown.front();
                if (timeAvail <= time) {
                    cooldown.pop();
                    complete.push(freq); 
                }
            }
            if (!complete.empty()) {
                int freq = complete.top(); 
                complete.pop();
                if (freq - 1 > 0) {
                    cooldown.push({freq - 1, time + n + 1});
                }
            }
            time++; 
        }
        return time; 
    }
};
