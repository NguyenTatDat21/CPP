#include<bits/stdc++.h>
using namespace std;

int a[200000];
int n;
long long res;


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        res += a[i];
    }
    long long tmp = res;
    sort(a+1, a+n+1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || a[i] != a[i-1]) {
            if (i != 1) {
                tmp = min(tmp, (long long) a[i-1] * cnt);
            }
            cnt = 1;
        }
        else {
            ++cnt;
        }
    }
    tmp = min(tmp, (long long) a[n] * cnt);
    printf("%lld", res - tmp);
}