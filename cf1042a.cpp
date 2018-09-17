#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int amax = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        amax = max(amax, a);
        sum += a;
    }
    int ans1 = (sum + m) / n;
    if ((sum + m) % n) ++ans1;
    ans1 = max(ans1, amax);
    int ans2 = amax + m; 
    printf("%d %d\n", ans1, ans2);
}