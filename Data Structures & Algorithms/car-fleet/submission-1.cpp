class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars[position[i]] = speed[i]; 
        }
        sort(position.begin(), position.end(), greater<int>()); 

        stack<double> times; 
        for (int i = 0; i < position.size(); ++i) {
            int currPos = position[i]; 
            int currSpeed = cars[position[i]];  

            double currTime = (double) (target - currPos) / currSpeed; 
            if (times.empty() || currTime > times.top()){
                times.push(currTime); 
            } 
        }
        return times.size(); 
    }
};
