#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            sum += x;
        }
        long long r = ((sum % 4) + 4) % 4;
        printf(r == 0 ? "YES\n" : "NO\n");
    }
    return 0;
}