#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        ll k;
        scanf("%d %lld", &n, &k);
        vector<ll> sum(n), t(n);   // t = -1 : not stuck, 0 : all equal, >0 : stuck escape cost
        ll minSum = LLONG_MAX, cap = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            sum[i] = a + b + c;
            minSum = min(minSum, sum[i]);
            if (a > b || a > c || b > c) t[i] = -1;
            else if (a == b && b == c) { t[i] = 0; cap = min(cap, sum[i]); }
            else t[i] = min(b - a, c - b) + 1;
        }
        ll lo = minSum, hi = min(cap, minSum + k + 3000000000LL);
        auto ok = [&](ll S) {
            ll total = 0;
            for (int i = 0; i < n; i++) {
                if (sum[i] >= S) continue;
                if (t[i] == 0) return false;
                ll need = S - sum[i] + (t[i] > 0 ? 2 * t[i] : 0);
                total += need;
                if (total > k) return false;
            }
            return true;
        };
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (ok(mid)) lo = mid; else hi = mid - 1;
        }
        printf("%lld\n", lo);
    }
}