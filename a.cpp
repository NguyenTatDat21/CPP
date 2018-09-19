#include<bits/stdc++.h>
using namespace std;
#define maxN 20000

typedef pair<pair<int, int>, int> condition;

condition s[maxN], ss[maxN];
int t[maxN], d[maxN];
map<int, int> f;
int cnt;
int l , n;



bool check(int x) {
    for (int i = 1; i <= x; ++i) {
        ss[i] = s[i];
    }
    sort(ss+1, ss+x+1);
    for (int i = 1; i <= cnt; ++i) d[i] = -1;
    for (int i = 1; i <= x; ++i) {
        int a = ss[i].first.first - 1;
        int b = ss[i].first.second;
        if (d[a] == -1 || d[b] == -1) {
            if (d[a] != -1) d[b] = (d[a] + ss[i].second) % 2;
            else if (d[b] != -1) d[a] = (d[b] + ss[i].second) % 2;
            else {
                d[a] = 0;
                d[b] = ss[i].second;
            }
        }
        else if ((d[a] + d[b]) % 2 != ss[i].second) return false;

    }
}

int main() {
    cin >> l >> n;
    for (int i = 1; i <= n; ++i) {
        string st;
        cin >> s[i].first.first >> s[i].first.second >> st;
        s[i].second = st == "odd";
        f[s[i].first.first] = 0;
        f[s[i].first.second] = 0;
    }
    cnt = 0;
    for (auto& x : f) {
        x.second = ++cnt;
    }
    for (int i = 1; i <= n; ++i) {
        s[i].first.first = f[s[i].first.first];
        s[i].first.second = f[s[i].first.second];
    }
    // for (int i = 1; i <= n; ++i) {cerr << s[i].first.first << " " << s[i].first.second << " " << s[i].second << endl;}
    int L = 1, R = n;
    int res = 0;
    while (L <= R) {
        int M = (L+R) / 2;
        // cerr << M << endl;
        if (check(M)) {
            res = M;
            L = M + 1;
        }
        else {
            R = M - 1;
        }
    }
    cout << res;
}