#include<bits/stdc++.h>
using namespace std;

long long a[200000], b[200000], suma[200000], sumb[200000], t[200000], pos[200000], m[200000];
int n;


bool cmp(int x, int y) {
    return (m[x] > m[y] || (a[x] - b[x]) * t[y] < (a[y] - b[y]) * t[x]);
}



void test() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &a[i], &b[i], &t[i]);
        pos[i] = i;
        if (a[i] == b[i] && t[i] == 0) m[i] = 1;
        else m[i] = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (m[pos[i]]) {
            swap(pos[++cnt], pos[i]);

        }
    }
    sort(pos + cnt + 1, pos + n + 1, cmp);
    suma[0] = 0;
    sumb[n+1] = 0;
    for (int i = 1; i <= n; ++i) {
        suma[i] = suma[i-1] + a[pos[i]];
    }
    for (int i = n; i >= 1; --i) {
        sumb[i] = sumb[i+1] + b[pos[i]];
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) 
        if (t[pos[i]]) {
            res += (suma[i] + sumb[i+1]) * t[pos[i]];
        }
    cerr << res << endl;
    // printf("%I64d.%I64d\n", res / 10000000, res % 10000000);
    printf("%.7f\n", (double) res /  10000000);
}

int main() {
    int t;
    scanf("%d", &t );
    while (t--) test();
}