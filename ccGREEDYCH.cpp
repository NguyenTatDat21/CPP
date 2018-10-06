#include<bits/stdc++.h>
using namespace std;

int nextInt() {
    int ret = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) {
        ret = ret * 10 + c - '0';
    }
    return ret;
}

int n;

int a[1000000];
vector<int> adj[1000000];
int f[500001][52], g[500001][52];

void visit(int u) {
    f[u][a[u]] = a[u];
    g[u][a[u]] = a[u];
    for (auto v : adj[u]) {
        // cerr << u << " " << v << endl;
        visit(v);
        for (int i = 1; i <= 50; ++i) {
            if (i < a[u]) {
                f[u][a[u]] = max(f[u][a[u]], f[v][i] + a[u]);
            }
            if (i > a[u]) {
                g[u][a[u]] = max(g[u][a[u]], g[v][i] + a[u]);
            }
            f[u][i] = max(f[u][i], f[v][i]);
            g[u][i] = max(g[u][i], g[v][i]);
            // cerr << g[u][i] << " " << g[v][i] << endl;

            // if (u == 4) {
                // cerr << g[u][i] << " " << g[v][i] << endl;
            // }
        }
    }
}


int main() {
    n = nextInt();
    // cerr << n << endl;
    for (int i = 1; i <= n; ++i) {
        a[i] = nextInt();
        // cerr << a[i] << endl;
    }
    for (int i = 2; i <= n; ++i) {
        int x = nextInt();
        // cerr << x << endl;
        adj[x].push_back(i);
    }
    int res = 0;
    visit(1);
    for (int i = 0; i <= 50; ++i) 
        for (int j = i + 1; j <= 51; ++j){
        res = max(res, f[1][i] + g[1][j]);
        // cerr << i << " " << f[1][i] << " " << g[1][i+1] << endl;
    }
    // cerr << g[1][5] << endl;
    printf("%d", res);

}