// Closest Subsequence Sum(leetcode 1755)
class Solution {
public:
    
    void generate(vector<int>& arr, vector<long long>& sums) {
        
        int n = arr.size();
        
        for(int mask = 0; mask < (1 << n); mask++) {
            
            long long sum = 0;
            
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    sum += arr[i];
                }
            }
            
            sums.push_back(sum);
        }
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int n = nums.size();
        
        vector<int> left, right;
        
        for(int i = 0; i < n / 2; i++)
            left.push_back(nums[i]);
            
        for(int i = n / 2; i < n; i++)
            right.push_back(nums[i]);
        
        vector<long long> leftSums, rightSums;
        
        generate(left, leftSums);
        generate(right, rightSums);
        
        sort(rightSums.begin(), rightSums.end());
        
        long long ans = LLONG_MAX;
        
        for(long long x : leftSums) {
            
            long long target = goal - x;
            
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);
            
            if(it != rightSums.end()) {
                ans = min(ans, llabs(x + *it - goal));
            }
            
            if(it != rightSums.begin()) {
                --it;
                ans = min(ans, llabs(x + *it - goal));
            }
        }
        
        return (int)ans;
    }
};