#include<bits/stdc++.h>
using namespace std;

long long a[200000];
int st[200000];
int top;

bool check(int x, int y, int z) {
    if ((a[y] - a[x]) * (z-y) < (a[z] - a[y]) * (y-x)) return false;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    st[top++] = 0;
    st[top++] = 1;
    for (int i = 2; i < n; ++i) {
        while (top > 1 && !check(st[top-2], st[top-1], i)) {
            --top;
        }
        st[top++] = i;
    }
    // for (int i = 0; i < top; ++i) cout << st[i] << endl;
    if ((a[st[1]] - a[st[0]]) * (st[top-1] - st[top-2]) < (a[st[top-2]] - a[st[top-1]]) * (st[1] - st[0])) {
        printf("%d %d", st[top-2]+1, st[top-1] + 1);
    }
    else printf("%d %d", st[0]+1, st[1]+1);
}