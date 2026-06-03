// Deficient Number (GFG)


class Solution {
  public:
  
    string isDeficient(int x) {
        
        long long sum = 0;
        
        // Find sum of all divisors
        for(int i = 1; i * i <= x; i++) {
            
            if(x % i == 0) {
                
                sum += i;
                
                // Add paired divisor
                if(i != x / i) {
                    sum += x / i;
                }
            }
        }
        
        // Check deficient condition
        if(sum < 2LL * x)
            return "YES";
            
        return "NO";
    }
};