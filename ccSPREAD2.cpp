#include<bits/stdc++.h>
using namespace std;

long long sum[200000];
int a[200000];

void test() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + a[i];
    long long i = 1;
    int res = 0;
    while (i < n) {
        ++res;
        i += sum[i];
    }
    printf("%d\n", res);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) test();
}