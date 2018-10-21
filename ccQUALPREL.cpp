#include<bits/stdc++.h>
using namespace std;

int a[200000];


void test() {
    int res;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1, greater<int>());
    for (int i = k; i <= n; ++i) {
        if (a[i] == a[k]) res = i;
        else break;
    }
    printf("%d\n", res);
}

int main() {
    int t;
    scanf("%d" , &t);
    while (t--) test();
}