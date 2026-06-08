// CSES Factory Machines
#include <bits/stdc++.h>
using namespace std;

bool canMake(vector<long long>& machines, long long t, long long time) {
    long long products = 0;

    for (long long x : machines) {
        products += time / x;

        if (products >= t)
            return true;
    }

    return false;
}

int main() {
    long long n, t;
    cin >> n >> t;

    vector<long long> machines(n);

    for (int i = 0; i < n; i++)
        cin >> machines[i];

    long long low = 1;
    long long high = 1e18;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canMake(machines, t, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
