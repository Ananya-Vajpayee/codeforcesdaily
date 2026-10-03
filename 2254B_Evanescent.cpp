#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        static char buf[200005];
        scanf("%s", buf);
        string s(buf);
 
        // Build runs: (start index 0-based, length, char)
        vector<int> runStart, runLen;
        vector<char> runChar;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            runStart.push_back(i);
            runLen.push_back(j - i);
            runChar.push_back(s[i]);
            i = j;
        }
 
        int R = (int)runStart.size();
        int maxReduction = 0;
 
        for (int r = 0; r < R; r++) {
            if (runLen[r] == 1) {
                int pos0 = runStart[r]; // 0-indexed position in string
                // valid deletion position: not first (0) or last (n-1) char
                if (pos0 >= 1 && pos0 <= n - 2) {
                    // singleton run always has a run before and after it
                    // (since pos isn't the global first/last char)
                    char leftChar  = runChar[r - 1];
                    char rightChar = runChar[r + 1];
                    int red = (leftChar == rightChar) ? 2 : 1;
                    maxReduction = max(maxReduction, red);
                }
            }
        }
 
        printf("%d\n", R - maxReduction);
    }
}