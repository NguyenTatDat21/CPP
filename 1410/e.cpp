#include<bits/stdc++.h>
using namespace std;
#define maxN 300000

int n, cnt;

int x[maxN], w[maxN], l[maxN], r[maxN];

map<int, int> m;

pair<int, int> a[maxN];

int BIT[2*maxN];

int get(int x) {
    int ret = 0;
    for (int xx = x; xx > 0; xx -= xx & (-xx)) {
        ret = max(ret, BIT[xx]);
    }
    return ret;
}

void update(int x, int v)  {
    for (int xx = x; xx <= cnt; xx += xx & (-xx)) {
        BIT[xx] = max(BIT[xx], v);
    }
}


int main() {
    scanf("%d",  &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x[i], &w[i]);
        l[i] = x[i] - w[i];
        r[i] = x[i] + w[i];
        m[l[i]] = 0;
        m[r[i]] = 0;
        // cerr << l[i] << " " << r[i] << endl;
    }
    cnt = 0;
    for (auto &x : m) {
        x.second = ++cnt;
    }

    for (int i = 1; i <= n; ++i) {
        a[i].first = m[l[i]];
        a[i].second = m[r[i]];
    }


    int res = 0;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        int tmp = (get(a[i].first) + 1);
        res = max(res, tmp);
        update(a[i].second, tmp);
        // cerr  << a[i].first << " " << a[i].second << " " << tmp << endl;
    }
    printf("%d\n", res);
}