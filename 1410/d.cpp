#include<bits/stdc++.h>
using namespace std;
#define MODULO 1000000007
#define maxN 1123


int a[maxN], s[maxN] ;
long long fact[1123456];
long long f[maxN];

int power(int a, int b) {
    if (b == 1) return a;
    long long tmp = power(a,b/2);
    //cerr << tmp << endl;
    tmp = (tmp * tmp) % MODULO;
    if (b % 2) tmp = (tmp * a) % MODULO;
    return tmp;
}


int C(int k, int n) {
    long long tmp = (fact[k] * fact[n-k]) % MODULO;  
    tmp = power(tmp, MODULO - 2);
    return (tmp * fact[n]) % MODULO;
}

int main() {
    int n;
    fact[0] = 1;
    for (int i = 1; i <= 1000000; ++i) fact[i] = (fact[i-1] * i) % MODULO;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i-1] * C(a[i] - 1, s[i-1] + a[i] - 1) % MODULO;
        // cerr << a[i] - 1 << " "  << s[i-1] + a[i] - 1 << endl;
    }
    printf("%d", f[n]);
}