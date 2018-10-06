#include<bits/stdc++.h>
using namespace std;

int main() {
    int res = 0;
    int l, L, x, n, a;
    scanf("%d%d%d", &n, &L, &a);
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x, &l);
        res += (x - t) / a;
        t = x + l;
    }
    res += (L - t) / a;
    printf("%d", res);
}