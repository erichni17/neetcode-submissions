class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(); 

        int first = 0, last = m; 
        int row; 
        while (first < last) {
            int mid = first + (last - first) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n-1]) {
                row = mid; 
                int l = 0, r = n; 

                while (l < r) {
                    int mid = l + (r - l) / 2; 
                    if (target == matrix[row][mid]) return true; 
                    else if (target < matrix[row][mid]) r = mid; 
                    else l = mid + 1; 
                }
                return false; 
            } else if (target < matrix[mid][0]) last = mid; 
            else {
                first = mid + 1; 
            }
        }
        return false; 
    }
};
