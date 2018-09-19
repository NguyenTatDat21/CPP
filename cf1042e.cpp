#include<bits/stdc++.h>
using namespace std;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            g[a[i][j]] = 0;
        }
    int cnt = 0;
    for (auto x : g) x.second = ++cnt;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) 
            a[i][j] = g[a[i][j]];
    return 0;
}
