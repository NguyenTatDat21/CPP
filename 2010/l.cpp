#include<bits/stdc++.h>
using namespace std;

// map<int>



long long cal(long long n)  {
    
    // cerr << n << endl;
    // if (dd[n]) return -1;
    // dd[n] = true;
    long long res = 0;
    if (n == 1) return 0;
    if (n % 2 == 0) {
        res =  cal(n / 2);
        if (res == -1) return res;
        res = res + n;
    }
    else {
        res = cal((n+1) / 2 * 3 - 1);
        if (res == -1) return res;
        res = res + n+1;
    }
    return res;
}



int main() {
    int n;
    // for (int i = 1; i <= 2000000; ++i) dd[i] = false; 
    scanf("%d", &n);
    printf("%I64d", cal(n));
}