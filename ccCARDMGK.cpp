#include<bits/stdc++.h>
using namespace std;

int a[200000];

void test() {
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (i != 1 && a[i] < a[i-1]) ++cnt;
    }
    if (a[1] < a[n]) ++cnt;
    // cerr << cnt << endl;
    if (cnt > 1) printf("NO\n");
    else printf("YES\n");
    
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
}