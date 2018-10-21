#include<bits/stdc++.h>
using namespace std;

int n;
int a[2000];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n / 2; ++i) {
        if (a[i] != a[n-i+1]) {
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}