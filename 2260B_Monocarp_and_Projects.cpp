#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long x, y, k;
        scanf("%lld %lld %lld", &x, &y, &k);
        long long d = y - x;
        long long hi = x + k - 1;
        long long ans = 0;
        for (long long a = x; a <= min(hi, d); a++)
            ans += d % a;
        long long lo = max(x, d + 1);
        if (lo <= hi)
            ans += (hi - lo + 1) * d;
        printf("%lld\n", ans);
    }
}