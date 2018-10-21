#include<bits/stdc++.h>
using namespace std;
#define MODULO 1000000007

long long fact[200000];
int a[200000];

void test() {
    int n;
    scanf("%d", &n);
    a[n+1] = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int pos = 0;
    long long cnt = 0;
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        ++cnt;
        if (a[i] != a[i+1]) {
            if (cnt > 1) {
                if (pos % 2 == 0) {
                    if (cnt % 2 != 0) {
                        res = (res * cnt) % MODULO;
                        --cnt;
                    }
                }
                else {
                    if (cnt % 2 == 0) {
                        res = ((res * cnt) % MODULO * (cnt-1)) % MODULO;
                        cnt -= 2;
                    } 
                    else {
                        res = (res * cnt) % MODULO;
                        --cnt;
                    }
                    
                }
                res = (res * fact[cnt]) % MODULO;
            }
            pos = i;
            cnt = 0;
        }
    }
    printf("%lld\n", res);
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 100000; ++i) 
        if (i % 2 == 1) {
            fact[i] = (fact[i-1] * i) % MODULO;
        }
        else fact[i] = fact[i-1];
    int t;
    scanf("%d", &t);
    while (t--) test();

}