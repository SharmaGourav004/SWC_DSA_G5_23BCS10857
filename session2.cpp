// Kth Smallest Instructions(leetcode 1643)
class Solution {
public:
    
    long long nCr(int n, int r) {
        if(r > n) return 0;
        
        long long res = 1;
        
        for(int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
        }
        
        return res;
    }
    
    string kthSmallestPath(vector<int>& destination, int k) {
        
        int v = destination[0]; // down moves
        int h = destination[1]; // right moves
        
        string ans = "";
        
        while(h > 0 || v > 0) {
            
            // Count paths if we place 'H' first
            if(h > 0) {
                long long cnt = nCr(h + v - 1, v);
                
                if(k <= cnt) {
                    ans += 'H';
                    h--;
                }
                else {
                    ans += 'V';
                    v--;
                    k -= cnt;
                }
            }
            else {
                ans += 'V';
                v--;
            }
        }
        
        return ans;
    }
};