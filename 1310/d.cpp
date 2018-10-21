#include<bits/stdc++.h>
using namespace std;
#define MODULO 1000000007


long long fact[2000000], sumFact[2000000], f[2000000];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i-1] * i) % MODULO;
    }
    for (int i = 1; i <= n; ++i) {
        sumFact[i] = (sumFact[i-1] + fact[i]) % MODULO;
    }
    long long res;
    if (n - 2 < k) res = 0;
    else {
        for (int i = k + 2; i <= n; ++i) {
            f[i] = ((f[i-1] * 2) % MODULO + (fact[i-2] * sumFact[i-k-1]) % MODULO) % MODULO;
            // cerr << i << " " << f[i] << " " << fact[i-2] << endl;
        }
        res = f[n];
    }
    printf("%d", res);
}