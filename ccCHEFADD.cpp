#include<bits/stdc++.h>
using namespace std;


long long f[40][40][40][2];
int a, b, c;

int getbit(int x, int i) {
    return (x >> (i-1)) & 1;
}



long long cal(int i, int j, int k, int l)  {
    // cerr << i << " " << j << " " << k << " " << l << endl;
    if (f[i][j][k][l] != -1) return f[i][j][k][l];
    long long ret;
    if (i == 0) {
        if (l == 0 && j == 0 && k == 0) ret = 1;
        else ret = 0;
    }
    else {
        ret = 0;
        if (l == 0) {
            if (getbit(c, i) == 0) {
                ret += cal(i-1, j, k, 0);
            }
            else {
                if (j > 0) ret += cal(i-1, j-1, k, 0);
                if (k > 0) ret += cal(i-1, j, k-1, 0);
                ret += cal(i-1, j ,k, 1);
            }
        }
        else {
            if (getbit(c, i) == 0) {
                if (j > 0) ret += cal(i-1, j-1, k, 1);
                if (k > 0) ret += cal(i-1, j, k-1, 1);
                if (j > 0 && k > 0) ret += cal(i-1, j-1, k-1, 0);
            }
            else {
                if (j > 0 && k > 0) ret += cal(i-1, j-1, k-1, 1);
            }
        }
    }
    f[i][j][k][l] = ret;
    return ret;
}

int test() {
    
    scanf("%d%d%d", &a, &b, &c);
    int m = __builtin_popcount(a);
    int n = __builtin_popcount(b);
    int p;
    for (p = 32; p >= 1; --p) 
        if (getbit(c, p)) break;
    for (int i = 0; i <= p; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= n; ++k) {
                for (int l = 0; l <= 1; ++l) 
                    f[i][j][k][l] = -1;
            }
        }
    }
    printf("%lld\n", cal(p, m, n, 0));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test();     
    }
}