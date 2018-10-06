#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        res = max(res, a+b);

    }
    printf("%d", res);
    return 0;
}