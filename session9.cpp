// cdeforces 1200E
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<string> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    string ans = v[0];

    for(int i = 1; i < n; i++) {

        string cur = v[i];

        int mx = 0;

        int len = min(ans.size(), cur.size());

        for(int k = 1; k <= len; k++) {

            string suf = ans.substr(ans.size() - k);
            string pre = cur.substr(0, k);

            if(suf == pre) {
                mx = k;
            }
        }

        ans += cur.substr(mx);
    }

    cout << ans;
}