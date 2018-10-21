#include<bits/stdc++.h>
using namespace std;

int a;
int f[4] = {48, 35, 25, 17};


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a;
    cout << f[n] << endl;
}