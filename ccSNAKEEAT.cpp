#include<bits/stdc++.h>
using namespace std;


int k[200000], l[200000], pos[200000], r[200000], res[200000];

bool cmp(int a, int b) {
    return pos[a] < pos[b];
}

void test() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &l[i]);
        pq.push(l[i]);
    }
    for (int i = 1; i <= q; ++i) {
        pos[i] = i;
        scanf("%d", &k[i]);
    }
    r[0] = pq.top();
    for (int i = 1; i <= n-1; ++i) {
        pq.pop();
        int a = pq.top() + 1;
        pq.pop();
        r[i] = min(a, pq.top());
        pq.push(a);
    }   
    r[n] = 2000000000;
    sort(pos+1, pos+q+1, cmp);
    int j = 0;
    for (int i = 1; i <= q; ++i) {
        while (k[pos[i]] < r[j]) ++j;
        res[pos[i]] = n - j;
    }
    for (int i = 1; i <= q; ++i) {
        printf("%d\n", res[i]);
    }

}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
}