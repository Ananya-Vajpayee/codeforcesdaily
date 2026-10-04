#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        printf("%lld\n", (1LL << (n - k + 1)) + 2 * (k - 1));
    }
}