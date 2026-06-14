// Maximum Area Rectangle gfg
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n), right(n);

        stack<int> st;

        // Previous Smaller
        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;

            ans = max(ans, heights[i] * width);
        }

        return ans;
    }

    int maxArea(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<int> height(m, 0);

        int ans = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};
