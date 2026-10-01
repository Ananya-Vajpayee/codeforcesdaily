#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, k, m;
        scanf("%lld %lld %lld", &n, &k, &m);
        
        if (k > m) {
            printf("NO\n");
        } else {
            printf("YES\n");
            for (long long i = 1; i <= n; i++) {
                long long val = (i % k == 0) ? (m - k + 1) : 1;
                printf("%lld ", val);
            }
            printf("\n");
        }
    }
    return 0;
}