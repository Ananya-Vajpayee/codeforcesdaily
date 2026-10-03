#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 998244353;
 
// Checks that a is "mountain shaped": non-decreasing then non-increasing,
// with no value shared between the increasing and decreasing parts
// (other than the single peak transition).
bool isMountain(const vector<long long>& a) {
    int m = (int)a.size();
    int i = 0;
    vector<char> seen(m + 2, 0);
 
    // climb: non-decreasing part
    while (i + 1 < m && a[i] <= a[i + 1]) {
        seen[a[i]] = 1;
        i++;
    }
 
    // descend: non-increasing part
    while (i + 1 < m && a[i] >= a[i + 1]) {
        i++;
        if (seen[a[i]]) return false; // value reused on both slopes -> invalid
    }
 
    return i == m - 1; // must have consumed the whole array
}
 
void solve() {
    long long n;
    cin >> n;
 
    int m = (int)n - 1;
    vector<long long> a(m);
    for (auto& x : a) cin >> x;
 
    long long ans = isMountain(a) ? 1 : 0;
 
    sort(a.begin(), a.end());
 
    // n itself can never appear as a cut value
    if (m > 0 && a[m - 1] == n) ans = 0;
 
    // for every repeated value at sorted index i (value x),
    // there are (x - i) ways to choose an unused smaller value
    for (int i = 1; i < m; i++) {
        if (a[i] == a[i - 1]) {
            ans = (ans * ((a[i] - i) % MOD + MOD)) % MOD;
        }
    }
 
    // n and (n-1) can be swapped at the two ends of the mountain
    ans = (ans * 2) % MOD;
 
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}