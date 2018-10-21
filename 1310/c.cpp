#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
long long row[2000000], col[2000000];


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    a.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        col[i] = col[i-1];
        a[i].push_back(0);
        for (int j = 1; j <= m; ++j) {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
            col[i] += x;
        }
    }
    for (int i = 1; i <= m; ++i) {
        row[i] = row[i-1];
        for (int j = 1; j <= n; ++j) {
            row[i] += a[j][i];
        }
    }
    int X, Y;
    int L = 1, R = n;
    while (L <= R) {
        int M = (L + R) / 2;
        if (col[M] >= (col[n]+1)/2) {
            X = M;
            R = M-1;
        }
        else L = M+1;
    }
    L = 1, R = m;
    while (L <= R) {
        int M = (L + R) / 2;
        if (row[M] >= (row[m]+1)/2) {
            Y = M;
            R = M-1;
        }
        else L = M+1;
    }
    long long res = 0;
    // for (int i = 1; i <= n; ++i) {for (int j = 1; j <= m; ++j) cerr << a[i][j]; cerr << endl;}
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) {
            res += (long long) a[i][j] * (abs(X - i) + abs(Y - j) + 1) * 2;
        }

    printf("%d %d %lld", X, Y, res);
}   