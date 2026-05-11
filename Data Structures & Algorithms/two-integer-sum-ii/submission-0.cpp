class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t n = numbers.size(); 
        size_t start = 0; 
        size_t end = numbers.size()-1; 
        while (true){
            int sum = numbers[start] + numbers[end]; 
            if (sum > target){
                end--; 
            }
            else if (sum < target){
                start++; 
            }
            else { // sum == target
                return {(int) start+1, (int) end+1}; 
            }
        }
    }
};
