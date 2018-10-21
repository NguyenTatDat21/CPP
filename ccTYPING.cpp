#include<bits/stdc++.h>
using namespace std;


int a[256];


void test() {
    int n;
    int cnt = 0;
    int res = 0;
    set<string> f;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int tmp = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (j == 0 || a[s[j]] != a[s[j-1]]) tmp += 2;
            else tmp += 4;
            // cout << tmp << endl;
        }
        if (f.find(s) != f.end()) tmp /= 2;
        else f.insert(s);
        res += tmp;
        // cout << tmp << endl;
    }
    cout << res << endl;
}

int main() {
    a['d'] = 1;
    a['f'] = 1;
    int t;
    cin >> t;
    while (t--) test();
}