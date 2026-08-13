class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = 0; //max bananas in 1 pile
        for (int num : piles) {
            maxB = max(maxB, num); 
        }

        int l = 1, r = maxB + 1; //r not inclusive
        while (l < r) {
            int rate = l + (r - l) / 2; 
            int time = timeFinish(piles, rate); 
            if (time > h) l = rate + 1; 
            else if (time <= h) r = rate; 
        }

        return l; 
    }
    int timeFinish(vector<int>& piles, int k) {
        int t = 0; 
        for (int b : piles) {
            t += b / k; 
            b = b % k; 
            if (b != 0) t++; 
        }
        return t; 
    }
};
