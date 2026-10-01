#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    string out;
    out.reserve(1 << 20);
 
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
 
        if (n < 2 * m) {
            out += "NO\n";
            continue;
        }
 
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
 
        bool ok = true;
        for (int j = 0; j < m; j++) {
            // count of a-elements strictly less than b[j]
            int cl = (int)(lower_bound(a.begin(), a.end(), b[j]) - a.begin());
            // need j+1 <= cl <= n - m + j
            if (cl < j + 1 || cl > n - m + j) {
                ok = false;
                break;
            }
        }
 
        out += ok ? "YES\n" : "NO\n";
    }
 
    cout << out;
    return 0;
}