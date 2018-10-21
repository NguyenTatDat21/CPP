#include<bits/stdc++.h>
using namespace std;
#define ep (long double) 1e-6

int n;
int x[112345], y[112345];
bool flag1 = false, flag2 = false;

bool check(long double k) {

    long double line = k;
    long double l = -20000000000000000;
    long double r = 20000000000000000;
    if (flag1) line = -k;
    for (int i = 1; i <= n; ++i) {
        long double dis = y[i] - line;
        if (abs(dis) > abs(k)) return false;
        l = max(l, x[i] - sqrt(k * k - dis * dis));
        r = min(r, x[i] + sqrt(k * k - dis * dis));
        if (l > r) return false;
    }
    // cout << k << " ";
    return true;

}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        if (y[i] < 0) flag1 = true;
        else flag2 = true;
    }
    long double res = 50000000000000;
    if (flag1 && flag2) res = -1;
    else {
        long double l = 0;
        long double r = 50000000000000;
        long double mid = (l + r) / 2;
        for (int i = 1; i <= 150; ++i) {
            mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
                res = mid;
            }
            else l = mid;
            
            // cerr << fixed << l << " " << r << " " << " " << mid << endl;
        }
        
        
        
    }
    cout << fixed << res << endl;
    // printf("%lf\n", res);
}