#include<bits/stdc++.h>
using namespace std;

#define INF 10000000000000

long long f[200000][4];
int n;
long long a[200000];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        f[i][1] = INF;
        f[i][2] = INF;
        f[i][3] = INF;
        if (a[i] == a[i-1]) {
            f[i][2] = min(f[i-1][1], f[i-1][2]);
            f[i][3] = f[i-1][2];
        }
        f[i][1] = min(f[i-1][2], f[i-1][3]);
        if (i > 1) f[i][2] = f[i-1][1] + a[i] - a[i-1];
        if (i > 2) f[i][3] = f[i-1][2] + a[i] - a[i-1];
    }
    printf("%I64d", min(f[n][2], f[n][3]));
}