// Minimize Max Distance to Gas Station gfg
class Solution {
public:
    
    bool canPlace(vector<int>& stations, int k, double dist) {
        int required = 0;

        for(int i = 0; i < stations.size() - 1; i++) {
            double gap = stations[i + 1] - stations[i];

            required += (int)ceil(gap / dist) - 1;

            if(required > k)
                return false;
        }

        return required <= k;
    }

    double findSmallestMaxDist(vector<int> &stations, int k) {

        double low = 0;
        double high = 0;

        for(int i = 0; i < stations.size() - 1; i++) {
            high = max(high,
                      (double)(stations[i + 1] - stations[i]));
        }

        while(high - low > 1e-6) {

            double mid = low + (high - low) / 2.0;

            if(canPlace(stations, k, mid))
                high = mid;
            else
                low = mid;
        }

        return high;
    }
};
