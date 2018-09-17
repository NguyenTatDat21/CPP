#include<bits/stdc++.h>
using namespace std;
#define maxN 300000

long long s[maxN], p[maxN];
int cnt;
map<long long, int> f;
long long BIT[2*maxN];

void update(int x) {
    for (int xx = x; xx > 0; xx -= (-xx) & xx) {
        ++BIT[xx];
    }
}

long long get(int x) {
    long long ret = 0;
    for (int xx = x; xx <= cnt; xx += (-xx) & xx) {
        ret += BIT[xx];
    }
    return ret;
}

int main() {
    int n;
    long long t;
    scanf("%d%I64d", &n, &t);
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        s[i] = s[i-1] + a;
        p[i] = s[i] - t; 
    }
    for (int i = 0; i <= n; ++i) 
        f[s[i]] = 0;
    for (int i = 0; i <= n; ++i) 
        f[p[i]] = 0;
    for (auto& x : f) {
        x.second = ++cnt;
    }
    for (int i = 0; i <= n; ++i) 
        s[i] = f[s[i]];
    for (int i = 0; i <= n; ++i) 
        p[i] = f[p[i]];
    update(s[0]);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += get(p[i] + 1);
        update(s[i]);
    }
    printf("%I64d", ans);
}