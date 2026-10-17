#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        static char buf[200005];
        scanf("%d %s", &n, buf);
        string s(buf);
        long long ans = 1;
        for (int par = 0; par < 2; par++) {
            int start = -1;      // forced first value of this chain, -1 if none yet
            bool bad = false;
            for (int i = par, p = 0; i < n; i += 2, p++) {
                if (s[i] == '?') continue;
                int need = (s[i] - '0') ^ (p & 1);
                if (start == -1) start = need;
                else if (start != need) { bad = true; break; }
            }
            if (bad) { ans = 0; break; }
            if (start == -1) ans = ans * 2 % MOD;
        }
        printf("%lld\n", ans);
    }
}