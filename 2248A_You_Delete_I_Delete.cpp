#include <bits/stdc++.h>
using namespace std;
 
string bobDelete(const string &t) {
    int pos = -1;
    for (int j = 0; j + 1 < (int)t.size(); j++) {
        if (t[j] == '1' && t[j+1] == '0') { pos = j; break; }
    }
    if (pos == -1) pos = t.rfind('1'); // no "10" pattern -> remove last '1'
    return t.substr(0, pos) + t.substr(pos + 1);
}
 
int main(){
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string best = "";
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0') {
                string t = s.substr(0, i) + s.substr(i + 1);
                string res = bobDelete(t);
                if (res > best) best = res;
            }
        }
        cout << best << "\n";
    }
}