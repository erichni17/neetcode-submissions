class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        uint32_t pow = 31; 
        while (n != 0) {
            rev += (n & 1) << pow; 
            pow--; 
            n = n >> 1; 
        }
        return rev; 
    }
};
