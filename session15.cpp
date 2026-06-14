// leetcode 1499
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        deque<pair<int,int>> dq;
        int ans = INT_MIN;

        for(auto &p : points) {

            int x = p[0];
            int y = p[1];

            while(!dq.empty() && x - dq.front().second > k)
                dq.pop_front();

            if(!dq.empty()) {
                ans = max(ans,
                          x + y + dq.front().first);
            }

            int value = y - x;

            while(!dq.empty() &&
                  dq.back().first <= value)
                dq.pop_back();

            dq.push_back({value, x});
        }

        return ans;
    }
};
