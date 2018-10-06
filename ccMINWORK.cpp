#include<bits/stdc++.h>
using namespace std;

int n;
int BIT[300000];
int l[200000], r[200000];
int m;
map<int, int> f;

void update(int x, int y) {
    for (int xx = x; xx <= m; xx += xx & (-xx)) {
        BIT[xx] += y;
    }
}

int get(int x) {
    int ret = 0;
    for (int xx = x; xx > 0; xx -= xx &  (-xx) ) {
        ret += BIT[xx];
    }
    return ret;
}



int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)  {
        scanf("%d%d", &l[i], &r[i]);
        f[l[i]] = 0;
        f[r[i]] = 0;
    }
    for (auto &x : f) {
        x.second = ++m;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        l[i] = f[l[i]];
        r[i] = f[r[i]];
        update(l[i], 1);
        update(r[i]+1, -1);
    }
    for (int i = 1; i <= m; ++i) {
        res = max(res, get(i));
    }
    printf("%d\n", res);
}