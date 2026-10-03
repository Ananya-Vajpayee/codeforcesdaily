#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        bool available[26] = {};
 
        string s;
 
        // First letters of original words
        for (int i = 0; i < n; i++) {
            cin >> s;
            available[s[0] - 'a'] = true;
        }
 
        bool ok = true;
 
        for (int i = 0; i < m; i++) {
            cin >> s;
 
            for (char c : s) {
                if (!available[c - 'A'])
                    ok = false;
            }
        }
 
        cout << (ok ? "YES" : "NO") << '\n';
    }
 
    return 0;
}