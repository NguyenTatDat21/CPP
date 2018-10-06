#include<bits/stdc++.h>
using namespace std;

int f[2000000];
bool mark[2000000];

void prime() {
    f[1] = 0;
    for (int i = 2; i <= 1000000; ++i) {
        f[i] = f[i-1];
        // if (i == 1000000) cout << i << endl;
        if (!mark[i]) {
            ++f[i];
            long long j = (long long) i * i;
            while (j <= 1000000) {
                mark[j] = true;
                j = j + i;
            }
        }
    }
}

int main() {
    prime();
    int q, n;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }
}