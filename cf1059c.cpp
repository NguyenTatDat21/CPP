#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int base = 1;
    while (n != 0) {
        if (n == 3) {
            printf("%d %d %d ", base, base, base * 3);
            break;
        }
        int t = n / 2 + n%2;
        n = n / 2;
        for (int i = 1; i <= t; ++i) {
            printf("%d ", base);

        }
        base = base * 2;

    }
}