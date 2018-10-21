#include<bits/stdc++.h>
using namespace std;

long long a[2000], b[2000];

int m, n;
long long MODULE;

long long mul(long long a, long long b) {
    if (b == 1) return a % MODULE;
    long long tmp = mul(a, b / 2);
    tmp = (tmp + tmp) % MODULE;
    if (b % 2) tmp = (tmp + a) % MODULE;
    return tmp;

}

int main() {
    scanf("%d%d%lld", &m, &n, &MODULE);
    for (int i = 1; i <= m; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long g = __gcd(a[i], b[j]);
            a[i] /= g;
            b[j] /= g;
        }
    }
    // for (int i = 1; i <= m; ++i) cerr << a[i] << endl;

    long long res1 = 1, res2 = 1;
    for (int i = 1; i <= m; ++i) res1 = mul(res1, a[i]);
    for (int i = 1; i <= n; ++i) res2 = mul(res2, b[i]);
    // for (int i = 1; i <= n; ++i) {cerr << b[i] << endl;}
    printf("%lld\n%lld", res1, res2);
}