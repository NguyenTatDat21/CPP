#include<bits/stdc++.h>
using namespace std;

int a[200000];

void test() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x - a[i];
    }
    for (int i = 1; i <= n-2; ++i) {
        if (a[i] < 0) {
            printf("NIE\n");
            return;
        }
        a[i+1] -= a[i] * 2;
        a[i+2] -= a[i] * 3;
        a[i] = 0;
    }
    if (a[n] == 0 && a[n-1] == 0) printf("TAK\n");
    else printf("NIE\n");
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) test();
}