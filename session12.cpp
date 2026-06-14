// codeforces 1011B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> freq(101, 0);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    auto can = [&](int days) {
        int people = 0;

        for (int cnt : freq) {
            people += cnt / days;
        }

        return people >= n;
    };

    int low = 1;
    int high = m;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (can(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
