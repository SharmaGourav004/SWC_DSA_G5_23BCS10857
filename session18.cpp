// Counting Towers cses
const int MOD = 1e9 + 7;

class Solution {
public:

    long long countTowers(int n) {

        vector<long long> full(n + 1);
        vector<long long> split(n + 1);

        full[1] = 1;
        split[1] = 1;

        for(int i = 2; i <= n; i++) {

            full[i] =
                (4LL * full[i - 1] + split[i - 1]) % MOD;

            split[i] =
                (full[i - 1] + 2LL * split[i - 1]) % MOD;
        }

        return (full[n] + split[n]) % MOD;
    }
};
