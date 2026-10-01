class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26); 

        int maxFreq = 0; 
        for (char t : tasks) {
            freq[t - 'A']++; 
            maxFreq = max(freq[t-'A'], maxFreq); 
        }

        int numMaxFreq = 0; 
        for (int f : freq) {
            if (f == maxFreq) {
                numMaxFreq++; 
            }
        }

        return max((int)tasks.size(), (maxFreq-1)*(n+1) + numMaxFreq); 

    }
};
