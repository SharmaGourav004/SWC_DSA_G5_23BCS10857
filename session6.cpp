// Number of Submatrices That Sum to Target(LEETCODE 1074)
class Solution {
public:
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int ans = 0;
        
        // Prefix sum row-wise
        for(int r = 0; r < rows; r++) {
            for(int c = 1; c < cols; c++) {
                matrix[r][c] += matrix[r][c - 1];
            }
        }
        
        // Fix left and right columns
        for(int left = 0; left < cols; left++) {
            
            for(int right = left; right < cols; right++) {
                
                unordered_map<int, int> mp;
                mp[0] = 1;
                
                int currSum = 0;
                
                for(int r = 0; r < rows; r++) {
                    
                    // Sum of current row between left and right
                    int rowSum = matrix[r][right];
                    
                    if(left > 0)
                        rowSum -= matrix[r][left - 1];
                    
                    currSum += rowSum;
                    
                    if(mp.count(currSum - target))
                        ans += mp[currSum - target];
                    
                    mp[currSum]++;
                }
            }
        }
        
        return ans;
    }
};