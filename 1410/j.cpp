#include<bits/stdc++.h>
using namespace std;

deque<int> qmax, qmin;

int a[200000];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    

    for (int i = 1; i <= k-1; ++i) {
        while (!qmax.empty() && a[i] >= a[qmax.back()]) qmax.pop_back();
        qmax.push_back(i);

        while (!qmin.empty() && a[i] <= a[qmin.back()]) qmin.pop_back();
        qmin.push_back(i);
    }

    int res = 2000000000;

    for (int i = k; i <= n; ++i) {
        while (!qmax.empty() && a[i] >= a[qmax.back()]) qmax.pop_back();
        qmax.push_back(i);
        if (qmax.front() < i - k + 1) qmax.pop_front();

        while (!qmin.empty() && a[i] <= a[qmin.back()]) qmin.pop_back();
        qmin.push_back(i);
        if (qmin.front() < i - k + 1) qmin.pop_front();

        int x = a[qmax.front()];
        int y = a[qmin.front()];
 

        res = min(res, min(abs(x), abs(y)) + abs(x - y));
    }
    printf("%d", res);
}