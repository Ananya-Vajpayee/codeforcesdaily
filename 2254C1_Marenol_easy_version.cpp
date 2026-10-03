#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        static char a[200005], b[200005];
        scanf("%s %s", a, b);
 
        long long totalA = 0, totalB = 0, oddA = 0, oddB = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                totalA++;
                if ((i + 1) % 2 == 1) oddA++;   // 1-indexed position, odd check
            }
            if (b[i] == '1') {
                totalB++;
                if ((i + 1) % 2 == 1) oddB++;
            }
        }
 
        bool ok = (totalA == totalB) && (oddA == oddB);
        puts(ok ? "YES" : "NO");
    }
}