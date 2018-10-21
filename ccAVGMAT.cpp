#include<bits/stdc++.h>
using namespace std;

void test() {
    int n, m;
    int a[400][400], cc[400][400], cp[400][400];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string st;
        cin >> st;
        for (int j = 1; j <= m; ++j) {
            if (st[j-1] == '1') a[i][j] = 1;
        
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cc[i][j] = cc[i-1][j-1] + a[i][j];
            cp[i][j] = cp[i-1][j+1] + a[i][j];
            // cerr << cc[i][j] << " ";
        }
        // cerr << endl;
    }
    for (int d = 1; d <= m + n - 2; ++d) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i][j]) {
                    int u = i + d;
                    int v = j;
                    if (u > n) {
                        v += u - n;
                        u = n;
                    }
                    res += cp[u][v]; 
                    u = i;
                    v = j + d;
                    if (v <= m) {
                        res -= cp[u][v];    
                    }
                    if  (v > m) {
                        u -= v - m;
                        v = m;
                    }
                    res += cc[u][v];
                    u = i - d;
                    v = j;
                    if (u >= 1) res -= cc[u][v];
                    // if (u >= 1) res -= cp[u][v];

                }
        cout << res << " ";
    }
    cout << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test();
    }
}