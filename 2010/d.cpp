#include<bits/stdc++.h>
using namespace std;

int a[200000];
int n, w;

bool check(int x) {
    int tmp = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        tmp = max(tmp, a[i]);
        if (i == n || i % x == 0) {
            sum += tmp;
            if (i < n) ++sum;
            tmp = 0;
            // if (x == 3) cerr << sum << endl;
            if (sum > w) return false;
        }
    }
    return true;
}


int main() {
    int res = 0;
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int l = 1, r = n;
    while (l <= r) {
        int m = (l+r) / 2;
        if (check(m)) {
            r = m - 1;
            res = m;
        }
        else l = m + 1;
    }
    printf("%d", res);
}