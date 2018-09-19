#include<bits/stdc++.h>
using namespace std;
#define maxN 20000

typedef pair<pair<int, int>, int> condition;

condition s[maxN], ss[maxN];
int d[maxN];
int cnt;
int l , n;
vector<pair<int, int>> adj[maxN];


bool visit(int u) {
    // cerr << u << endl;
    for (auto x : adj[u]) {
        int v = x.first;
        int c = x.second;
        // cerr << u << " " << v << endl;
        if (d[v] == -1) {
            d[v] = (d[u] + c) % 2;
            if (!visit(v)) return false;
        }
        else {
            if (d[v] != (d[u] + c) % 2) 
            return false;
        }
    }
    return true;
} 

bool check(int x) {
    for (int i = 0; i <= cnt; ++i) {
        adj[i].clear();
        d[i] = -1;
    }
    for (int i = 1; i <= x; ++i) {
        int u = s[i].first.first - 1;
        int v = s[i].first.second;
        int c = s[i].second;
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }

    for (int i = 0; i <= cnt; ++i) {
        if (d[i] == -1) {
            d[i] = 0;
            if (!visit(i)) return false;
        }
    }
    return true;
}

bool test() {
    cin >> l;
    if (l == -1) return false; 
    cin >> n;
    map<int, int> f;
    for (int i = 1; i <= n; ++i) {
        string st;
        cin >> s[i].first.first >> s[i].first.second >> st;
        s[i].second = (st == "odd");
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
        // cerr << endl << M << endl;
        if (check(M)) {
            res = M;
            L = M + 1;
        }
        else {
            R = M - 1;
        }
    }
    cout << res << endl;
    return true;
}

int main() {
    // freopen("a.txt", "r", stdin);
    while (test()) ;
    // fclose(stdin);
}