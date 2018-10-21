#include<bits/stdc++.h>
using namespace std;

int a[20][20];


int main() {
    int n;
    while (true) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        if (u == 0) break;
        a[u][v] = c;
        a[v][u] = c;
    }
    int res = 0;
    for (int i = 1; i <= 12; ++i)
        for (int j = i+1; j <= 12; ++j) 
            for (int k = j+1; k <= 12; ++k) 
                if (a[i][j] && a[j][k] && a[k][i] && (a[i][j] != a[j][k] || a[j][k] != a[k][i] || a[k][i] != a[i][j])) {
                    cout << i << " " << j << " " << k << endl;
                    ++res;
                }
    cout << res << endl;
}