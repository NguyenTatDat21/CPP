#include<bits/stdc++.h>
using namespace std;

int l, n;
int a[200000];

bool check(int x) {
    int cur = -1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (cur == -1 || (cur & a[i]) < x) {
            cur = a[i];
            ++cnt;
            if (cnt > l) return false;
        }
        else {
            cur = cur & a[i];
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &l);
    int L = 0;
    int R = 1000000000;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        R = min(R, a[i]);
    }
    int res = 0;
    while (L <= R) {
        int M = (L+R) / 2;
        if (check(M)) {
            res = M;
            L = M + 1;
        }
        else R = M-1;
    }
    printf("%d\n", res);
}