#include<bits/stdc++.h>
using namespace std;
#define base 998244353

int f[2000][2500][4];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    f[1][1][0] = 1;
    f[1][1][3] = 1;
    f[1][2][1] = 1;
    f[1][2][2] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int p = 0; p < 4; ++p) {
                if (f[i][j][p]) {
                    for (int q = 0; q < 4; ++q) {
                        int h = 0;
                        if (p != q) {
                            if (q == 1 || q == 2) {
                                ++h;
                                if (p == 1 || p == 2) ++h;
                            }
                            else {
                                if (p == 0 || p == 3) ++h;
                            }
                        }
                        f[i+1][j+h][q] += f[i][j][p];
                        f[i+1][j+h][q] %= base;
                    }
                }
            }
        }
    }
    // for (int i = 1; i <= n; ++i) {for (int j = 1; j <= k; ++j) {for (int q = 0; q < 4; ++q) cerr << f[i][j][q] << " ";cerr << endl;}}
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += f[n][k][i];
        ans %= base;
    }
    printf("%d", ans);
}