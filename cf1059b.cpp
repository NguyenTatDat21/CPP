#include<bits/stdc++.h>
using namespace std;

bool a[2000][2000], b[2000][2000];
int m, n;
int xx[8] = {0,-1,-1,-1,0,1,1,1};
int yy[8] = {1,1,0,-1,-1,-1,0,1};
 
int main() {
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c = getchar();
            a[i][j] =  (c == '#');

        }
        char c = getchar();
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {

                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + xx[k];
                    int y = j + yy[k];
                    if (a[x][y]) ++ cnt;
                }
                // if (i == 3 && j == 5) cerr << cnt << endl;
                if (cnt == 8) {
                    for (int k = 0; k < 8; ++k) {
                        int x = i + xx[k];
                        int y = j + yy[k];
                        b[x][y] = true;
                    }
                }
        }
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != b[i][j]) {
                ok = false;
                break;
            }
        }  
        if (!ok) break;
    }
    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cerr << b[i][j];
        }
        cerr << endl;
    }
    */
    printf("%s", ok ? "YES" : "NO");
}